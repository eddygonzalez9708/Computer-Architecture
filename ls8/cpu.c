#include <stdio.h> 
#include <stdlib.h> 
#include "cpu.h"

unsigned char cpu_ram_read(struct cpu *cpu, unsigned char MAR) {
  return cpu->ram[MAR]; 
} 

void cpu_ram_write(struct cpu *cpu, unsigned char MAR, unsigned char MDR) {
  cpu->ram[MDR] = MDR; 
} 

/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */

void cpu_load(struct cpu *cpu)
{
  const int DATA_LEN = 6;
  // const char data[DATA_LEN] = {
    char data [6] = {
    // From print8.ls8
    0b10000010, // LDI R0,8
    0b00000000,
    0b00001000,
    0b01000111, // PRN R0
    0b00000000,
    0b00000001  // HLT
  };

  int address = 0;

  for (int i = 0; i < DATA_LEN; i++) {
    if (address > 255) {

    }
    cpu->ram[address++] = data[i];
  }

  // TODO: Replace this with something less hard-coded
}

/**
 * ALU
 */
void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB)
{
  switch (op) {
    case ALU_MUL:
      // TODO
      break;
    
    case ALU_ADD: 
      // TODO 
      break; 

    // TODO: implement more ALU ops
  }
}

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
  int running = 1; // True until we get a HLT instruction

  while (running) {
    // TODO
    // 1. Get the value of the current instruction (in address PC).
    // 2. switch() over it to decide on a course of action.
    // 3. Do whatever the instruction should do according to the spec.
    // 4. Move the PC to the next instruction.

    unsigned char IR = cpu_ram_read(cpu, cpu->pc); 

    unsigned char operandA = cpu_ram_read(cpu, cpu->pc + 1); 
    unsigned char operandB = cpu_ram_read(cpu, cpu->pc + 2); 

    // printf("TRACE: %02x: %02x\n", cpu->pc, IR); 

    switch (IR) {
      case LDI: 
        cpu->reg[operandA] = operandB; 
        break; 

      case PRN: 
        printf("%d\n", cpu->reg[operandA]); 
        break; 

      case HLT: 
        running = 0; 
        break; 

      default: 
        printf("unknown insruction at %02x: %02x\n", cpu->pc, IR);
        exit(2);  
    }
    cpu->pc += (IR >> 6) + 1; 
  }
}

/**
 * Initialize a CPU struct
 */

void cpu_init(struct cpu *cpu)
{
  // TODO: Initialize the PC and other special registers
  cpu->pc = 0; 

  // TODO: Zero registers and RAM
}
