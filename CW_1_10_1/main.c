#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint32_t bit_input;
    uint32_t total_bits;
    uint8_t result_output;
    uint8_t current_state;
    uint8_t previous_state;
} FiniteStateMachine;

FiniteStateMachine FSM;
uint8_t test_count = 0;

void OddsDetector(uint32_t input_bits);
void PrintOutput(void);

int main(void)
{
    FSM.previous_state = 0;

    printf("\n------------------------------------\n");
    printf("     Finite State Machine Tests     ");
    printf("\n------------------------------------\n");

    uint32_t test_data_0 = 0b1001011000010;
    uint32_t test_data_1 = 0b10110011000;
    uint32_t test_data_2 = 0b10101001001010001001;
    uint32_t test_data_3 = 0b101001;
    uint32_t test_data_4 = 0b101111101;

    OddsDetector(test_data_0);
    PrintOutput();
    OddsDetector(test_data_1);
    PrintOutput();
    OddsDetector(test_data_2);
    PrintOutput();
    OddsDetector(test_data_3);
    PrintOutput();
    OddsDetector(test_data_4);
    PrintOutput();
    printf("\n");

    return 0;
}

void OddsDetector(uint32_t input_bits)
{
    FSM.previous_state = FSM.current_state;
    FSM.bit_input = input_bits;
    FSM.total_bits = 0;

    while (input_bits) {
        FSM.total_bits++;
        input_bits >>= 1;
    }

    if (FSM.total_bits % 2) {
        FSM.current_state = 1;
        FSM.result_output = 1;
    } else {
        FSM.current_state = 0;
        FSM.result_output = 0;
    }
}

void PrintOutput(void)
{
    char prev_state[10];
    char curr_state[10];
    ++test_count;

    if (FSM.previous_state == 0) {
        memcpy(prev_state, "EVEN", 5);
    } else {
        memcpy(prev_state, "ODD", 4);
    }

    if (FSM.current_state == 0) {
        memcpy(curr_state, "EVEN", 5);
    } else {
        memcpy(curr_state, "ODD", 4);
    }
    printf("\n------------------------------------\n");
    printf("Test no: %d\n", test_count);
    printf("Number of bits %d\n", FSM.total_bits);
    printf("The previous state was: %s\n", prev_state);
    printf("The current state is %s\n", curr_state);
    printf("The output is: %d\n", FSM.result_output);
    printf("------------------------------------\n");
}