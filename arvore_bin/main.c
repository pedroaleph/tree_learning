#include <stdio.h>
#include <stdlib.h>
#include "arv_bin.h"

int main()
{
    //nao testei com outros exemplos de arvore, mas irei fazer
    Arv_bin* arv = nova_arv(nova_arv_no('a',
                                        nova_arv_no('b',nova_arv_no('d',NULL,NULL)
                                                    ,nova_arv_no('e',NULL,NULL)),
                                        nova_arv_no('c',nova_arv_no('f',NULL,NULL),
                                                    nova_arv_no('g',NULL,NULL))));

    arv_print_pre(arv);
    //printf("h = %d\n",arv_altura(arv));
    //printf("%d\n",tamanho(arv));
    //printf("%d\n",arv_folhas(arv));
    //arv_estrita(arv);
    //arv_completa(arv);

    arv_libera(arv);



    return 0;

}
