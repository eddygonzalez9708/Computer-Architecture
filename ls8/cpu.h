// a directive that allows for conditional compilation
#ifndef _CPU_H_
#define _CPU_H_

// Holds all information about the CPU
struct cpu {
  // TODO
  unsigned char pc; // PC
  unsigned char reg[8]; // registers (array)
  unsigned char ram[256]; // ram (array)
};

// Other general purpose register names 
#define SP 7

// ALU operations
enum alu_op {
  ALU_MUL, 
  ALU_ADD
}; 

// Instructions

// These use binary literals. If these aren't available with your compiler, hex
// literals should be used.

// ALU ops 

#define ADD 0b10100000
#define SUB 0b10100001
#define MUL 0b10100010
#define DIV 0b10100011
#define MOD 0b10100100
#define INC 0b01100101
#define DEC 0b01100110
#define CMP 0b10100111 
#define AND 0b10101000 
#define OR  0b10101010 
#define XOR 0b10101011 
#define SHL 0b10101100 
#define SHR 0b10101101 

// PC mutators 

#define CALL 01010000
#define RET  00010001
#define INT  01010010 
#define IRET 00010011
#define JMP  01010100 
#define JEQ  01010101 
#define JNE  01010110 
#define JGT  01010111 
#define JLT  01011000 
#define JLE  01011001 
#define JGE  01011010 

// Other 

#define NOP  0b00000000
#define HLT  0b00000001 
#define LDI  0b10000010
#define LD   0b10000011
#define ST   0b10000100
#define PUSH 0b01000101
#define POP  0b01000110
#define PRN  0b01000111
#define PRA  0b01001000

// TODO: more instructions here. These can be used in cpu_run().

// Function declarations

/* It is extends the visibility of variables and fucntions. 
It also means the storage for this function is allocated in another file. */ 

extern void cpu_load(struct cpu *cpu, char *filename);
extern void cpu_init(struct cpu *cpu);
extern void cpu_run(struct cpu *cpu);

#endif
