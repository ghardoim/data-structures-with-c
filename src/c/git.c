#include "../h/terminal.h"
#include "../h/mainLib.h"

void commitDoPaciente(PACIENTE* umPaciente) {
    systemCL("git add resrc/pacientes.csv");
    systemCL("echo 'Comitando dados do novo paciente'");
    // systemCL("git commit -m \"commitando  paciente: %s\" --all", umPaciente->individuo.nome);
}
