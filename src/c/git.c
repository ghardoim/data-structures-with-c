#include "../h/terminal.h"
#include "../h/mainLib.h"
#include "../h/git.h"

void commitDoPaciente(PACIENTE* umPaciente) {
    systemCL("git add .");
    systemCL("git commit -m \"commitando o paciente: %s\" --all", umPaciente->individuo.nome);
}
