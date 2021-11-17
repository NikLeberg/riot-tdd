#include <stdio.h>
#include <string.h>

#include "thread.h"
#include "shell.h"
#include "shell_commands.h"

#include "ukal.h"
#include "hello_module.h"

static int hello_world(int argc, char **argv)
{
    /* Suppress compiler errors */
    (void)argc;
    (void)argv;
    printf("hello world!\n");
    return 0;
}

static int filter2(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    //Filter_t filter;
    const Index_t n_states = 4;
    const Index_t n_measurements = 2;

    Matrix_t y;
    ulapack_init(&y, n_measurements, 1);
    Matrix_t x;
    ulapack_init(&x, n_states, 1);
    Matrix_t Phi;
    ulapack_init(&Phi, n_states, n_states);
    Matrix_t gamma;
    ulapack_init(&gamma, n_states, 2);
    Matrix_t Q;
    ulapack_init(&Q, gamma.n_cols, gamma.n_cols);
    Matrix_t P;
    ulapack_init(&P, n_states, n_states);
    Matrix_t H;
    ulapack_init(&H, n_measurements, n_states);
    Matrix_t R;
    ulapack_init(&R, n_measurements, n_measurements);
    Matrix_t fx;
    ulapack_init(&fx, n_states, 1);
    Matrix_t Hx;
    ulapack_init(&Hx, n_measurements, 1);

    ukal_filter_create(NULL, ekf, n_states, n_measurements, NULL, NULL, NULL, NULL, NULL, NULL,
                       NULL);

    return 0;
}

const shell_command_t shell_commands[] = {
    { "hello", "prints hello world", hello_world },
    { "filter", "inits uKal ekf", filter2 },
    { NULL, NULL, NULL }
};

int main(void)
{
    char line_buf[SHELL_DEFAULT_BUFSIZE];

    shell_run(shell_commands, line_buf, SHELL_DEFAULT_BUFSIZE);
    return 0;
}
