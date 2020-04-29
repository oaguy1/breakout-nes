
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// include NESLIB header
#include "neslib.h"

// include CC65 NES Header (PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// BCD arithmetic support
#include "bcd.h"
//#link "bcd.c"

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"

# define ROW_SIZE 15
# define NUM_ROWS 5

typedef struct brick {
  int x;
  int y;
  int pal;
} Brick;

Brick bricks[ROW_SIZE * NUM_ROWS];

const int TRANS_FLAG_PAL[5] = {2, 3, 1, 3, 2};

/*{pal:"nes",layout:"nes"}*/
const char PALETTE[32] = { 
  0x03,			// screen color

  0x21,0x24,0x20,0x00,	// background palette 0
  0x1C,0x20,0x2C,0x00,	// background palette 1
  0x00,0x10,0x20,0x00,	// background palette 2
  0x06,0x16,0x26,0x00,   // background palette 3

  0x16,0x35,0x24,0x00,	// sprite palette 0
  0x00,0x37,0x25,0x00,	// sprite palette 1
  0x0D,0x2D,0x3A,0x00,	// sprite palette 2
  0x0D,0x27,0x2A	// sprite palette 3
};


void draw_brick(int a, int b, int pal) {
  vram_adr(NTADR_A(a,b));
  vram_fill(pal,2);
}


void init_bricks() {
  int i,j;
  for(i = 0; i < NUM_ROWS; i++) {
    
  }
}

// setup PPU and tables
void setup_graphics() {
  // clear sprites
  oam_clear();
  // set palette colors
  pal_all(PALETTE);
}

void main(void)
{
  setup_graphics();
  
  // draw bricks
  vram_adr(NTADR_A(1,1));
  vram_fill(2,30);
  vram_adr(NTADR_A(1,2));
  vram_fill(1,30);
  vram_adr(NTADR_A(1,3));
  vram_fill(3,30);
  
  // enable rendering
  ppu_on_all();
  // infinite loop
  while(1) {
  }
}
