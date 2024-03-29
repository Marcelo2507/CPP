import android.bluetooth.BluetoothAdapter;
import android.bluetooth.BluetoothDevice;
import android.bluetooth.BluetoothSocket;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.HashMap;
import java.util.UUID;

public class MainActivity extends AppCompatActivity {

    private BluetoothAdapter bluetoothAdapter;
    private BluetoothSocket bluetoothSocket;
    private InputStream inputStream;
    private OutputStream outputStream;
    private TextView textView;
    private GamepadRecordingManager gamepadRecordingManager;
    private boolean isBluetoothConnected = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textView = findViewById(R.id.textView);
        textView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if (event.getAction() == MotionEvent.ACTION_DOWN && isBluetoothConnected) {
                    sendClickEvent(event.getX(), event.getY());
                }
                return true;
            }
        });

        bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        if (bluetoothAdapter == null) {
            showMessageAndFinish("Bluetooth not supported");
            return;
        }

        if (!bluetoothAdapter.isEnabled()) {
            showMessageAndFinish("Please enable Bluetooth");
            return;
        }

        gamepadRecordingManager = new GamepadRecordingManager();
        connectToBluetoothDevice("XX:XX:XX:XX:XX:XX"); // Substitua pelo endereço do dispositivo Bluetooth
    }

    private void showMessageAndFinish(String message) {
        Toast.makeText(this, message, Toast.LENGTH_SHORT).show();
        finish();
    }

    private void connectToBluetoothDevice(String deviceAddress) {
        BluetoothDevice device = bluetoothAdapter.getRemoteDevice(deviceAddress);
        UUID uuid = UUID.fromString("00001101-0000-1000-8000-00805F9B34FB"); // UUID para SPP (Serial Port Profile)

        try {
            bluetoothSocket = device.createRfcommSocketToServiceRecord(uuid);
            bluetoothSocket.connect();
            inputStream = bluetoothSocket.getInputStream();
            outputStream = bluetoothSocket.getOutputStream();
            isBluetoothConnected = true;
            startReadingData();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void startReadingData() {
        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    byte[] buffer = new byte[1024];
                    int bytes;
                    while (true) {
                        bytes = inputStream.read(buffer);
                        final String data = new String(buffer, 0, bytes);
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                updateUIWithData(data);
                            }
                        });
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

    private void updateUIWithData(String data) {
        textView.setText(data);
    }

    private void sendClickEvent(float x, float y) {
        try {
            String clickData = "CLICK:" + x + "," + y;
            outputStream.write(clickData.getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        try {
            isBluetoothConnected = false;
            if (bluetoothSocket != null) {
                bluetoothSocket.close();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void onGamepadButtonDown(int keyCode) {
        if (isBluetoothConnected) {
            gamepadRecordingManager.recordButtonPress(keyCode);
            gamepadRecordingManager.playbackAction(keyCode);
        }
    }

    public void onGamepadButtonUp(int keyCode) {
        if (isBluetoothConnected) {
            gamepadRecordingManager.recordButtonRelease(keyCode);
        }
    }
}

class GamepadRecordingManager {

    private HashMap<Integer, Long> buttonPressStartTimeMap;

    public GamepadRecordingManager() {
        buttonPressStartTimeMap = new HashMap<>();
    }

    public void recordButtonPress(int keyCode) {
        buttonPressStartTimeMap.put(keyCode, System.currentTimeMillis());
    }

    public void recordButtonRelease(int keyCode) {
        if (buttonPressStartTimeMap.containsKey(keyCode)) {
            long pressStartTime = buttonPressStartTimeMap.get(keyCode);
            long pressDuration = System.currentTimeMillis() - pressStartTime;
            // Aqui você pode armazenar a ação (keyCode e pressDuration) em uma estrutura de dados para reprodução futura
            buttonPressStartTimeMap.remove(keyCode);
        }
    }

    public void playbackAction(int keyCode) {
        // Aqui você pode verificar se há uma ação gravada associada a este keyCode
        // e reproduzir a ação correspondente na tela do dispositivo
    }
}
