#include <stdio.h>
using namespace std;

// Definição de estrutura para um processo
typedef struct Process {
    int pid; // ID do processo
    int priority; // Prioridade do processo
    int status; // Status do processo (ativo, bloqueado, etc.)
    // Outros campos podem ser adicionados conforme necessário
} Process;

// Função para inicializar o kernel
void initialize_kernel() {
    // Inicializar processos, interrupções, etc.
    printf("Kernel inicializado!\n");
}

// Função para criar um novo processo
Process create_process(int pid, int priority) {
    Process new_process;
    new_process.pid = pid;
    new_process.priority = priority;
    new_process.status = 1; // Status 1 indica processo ativo
    printf("Processo criado: PID = %d, Prioridade = %d\n", pid, priority);
    return new_process;
}

// Função para lidar com uma interrupção
void handle_interrupt(int interrupt_code) {
    // Lidar com a interrupção específica
    printf("Interrupção recebida: Código = %d\n", interrupt_code);
}

int main() {
    // Inicializar o kernel
    initialize_kernel();

    // Criar alguns processos de exemplo
    Process process1 = create_process(1, 10);
    Process process2 = create_process(2, 5);

    // Simular algumas interrupções
    handle_interrupt(1);
    handle_interrupt(2);

    return 0;
}
