// FalseGhost

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void error() {
	printf("Usage: durga_conf ['update', 'upgrade', 'edit']");
	printf("Update: Re-Build Durga w/ your updated extensions");
	printf("Upgrade: Get Latest Release from GH, saving your extensions");
	printf("Edit: Edit Extensions File with $EDITOR");
}

void upgrade() {
    printf("Creating Copy of ~/.durga/Durga/src/extensions.rs...\n");
    system("mv ~/.durga/Durga/src/extensions.rs /tmp/durgaexttmp.rs");
    printf("Deleting Old Version...\nGetting New One...\n");
    system("rm -rf ~/.durga/Durga");
    system("git clone https://github.com/ToBeatELIT3/Durga ~/.durga/Durga");
    printf("Moving Extensions back...\n");
    system("rm ~/.durga/Durga/src/extensions.rs");
    system("mv /tmp/durgaexttmp.rs ~/.durga/Durga/src/extensions.rs");
    printf("Done!\n");
}

void update() {
    printf("Builing Durga..");
    system("sudo rm /bin/durga");
    system("cd ~/.durga/Durga && cargo build --release && sudo mv target/release/durga /bin/durga");
    printf("Done!\n");
}

void edit() {
    system("$EDITOR ~/.durga/Durga/src/extensions.rs");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
	error();
    } else {
	if (strcmp( argv[2], "upgrade") == 0) { upgrade(); }
	else if (strcmp( argv[2], "update") == 0) { update(); }
	if (strcmp( argv[2], "edit") == 0) { edit(); }
	else { error(); }
    }
    return 0;
}
