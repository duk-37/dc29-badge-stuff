#include "music.h"


// everything needs to be position independent here
// so that means
// 1. no functions aside from main
// 2. no data accesses
// we also don't want to overwrite anything important, so:
// 3. no static variables

__attribute__((always_inline)) static void buzz(int delay /* don't actually know what this is but i think it's some timer delay thing */) {
	unsigned *buzzer = (unsigned*)DATA_BUZZER;
	FUNC_SETUP_TIMER(*buzzer);
	FUNC_TRIGGER_TIMER(buzzer, 0, delay);	
}

__attribute__((always_inline)) static void update_led(int led, uint8_t *col) {
	FUNC_UPDATE_LED(led, col);
}

__attribute__((always_inline)) static void play_song(int * song, int song_len)
{
	uint8_t colors[4][3] = {{0}};
	int spin[4] = {0};
	
	colors[0][0] = 255;
	colors[0][1] = 255;
	colors[0][2] = 0;
	
	colors[1][0] = 0;
	colors[1][1] = 255;
	colors[1][2] = 255;
	
	colors[2][0] = 255;
	colors[2][1] = 0;
	colors[2][2] = 255;
	
	colors[3][0] = 255;
	colors[3][1] = 255;
	colors[3][2] = 255;
	
	spin[0] = 1;
	spin[1] = 2;
	spin[2] = 3;
	spin[3] = 0;

	for (int seq = 0; seq < song_len; ++seq) 
	{
		uint8_t oldcolors[4][3];
		for (int i = 0; i < 4; ++i) 
		{
			oldcolors[i][0] = colors[i][0];
			oldcolors[i][1] = colors[i][1];
			oldcolors[i][2] = colors[i][2];
			
			update_led(i + 1, colors[i]);
		}
		
		for (int i = 0; i < 4; ++i) 
		{
			colors[i][0] = oldcolors[spin[i]][0];
			colors[i][1] = oldcolors[spin[i]][1];
			colors[i][2] = oldcolors[spin[i]][2];
		}
		
		buzz(song[seq]);
		
		for (volatile int i = 0; i < 230000; ++i);
	} 
}

int _start(void)
{		
	int sandstorm[200];
	int soviet[200];
	int starwars[250];
	
	// this only really works for a very limited set of frequencies
	int magic = 400000;
	
	int c5 = magic / 523;
	int d5 = magic / 587;
	int e5 = magic / 659;
	int f5 = magic / 698;
	int g5 = magic / 784;

	int a5 = magic / 880;
	int asharp5 = magic / 932;
	int b5 = magic / 988;
	
	int c6 = magic / 1047;
	int d6 = magic / 1174;
	int e6 = magic / 1318;
	int f6 = magic / 1396;
	int g6 = magic / 1568;

	int len_starwars = 0;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = c5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = e5;
	starwars[len_starwars++] = e5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = e5;
	starwars[len_starwars++] = e5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = c6;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = g5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = e5;
	starwars[len_starwars++] = e5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = f5;
	starwars[len_starwars++] = 0;

	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = d5;
	starwars[len_starwars++] = 0;

	
	// lord have mercy on my soul
	int len_soviet = 0;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = f6;
	soviet[len_soviet++] = f6;
	soviet[len_soviet++] = f6;
	soviet[len_soviet++] = f6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = e6;
	soviet[len_soviet++] = e6;
	soviet[len_soviet++] = e6;
	soviet[len_soviet++] = e6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = a5;
	soviet[len_soviet++] = a5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = a5;
	soviet[len_soviet++] = a5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = asharp5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = f5;
	soviet[len_soviet++] = f5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = f5;
	soviet[len_soviet++] = f5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = g5;
	soviet[len_soviet++] = g5;
	soviet[len_soviet++] = g5;
	soviet[len_soviet++] = g5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = g5;
	soviet[len_soviet++] = g5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = a5;
	soviet[len_soviet++] = a5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = b5;
	soviet[len_soviet++] = b5;
	soviet[len_soviet++] = b5;
	soviet[len_soviet++] = b5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = b5;
	soviet[len_soviet++] = b5;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = c6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = d6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = e6;
	soviet[len_soviet++] = e6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = f6;
	soviet[len_soviet++] = f6;
	soviet[len_soviet++] = 0;
	soviet[len_soviet++] = g6;
	soviet[len_soviet++] = g6;
	soviet[len_soviet++] = g6;
	soviet[len_soviet++] = g6;
	soviet[len_soviet++] = 0;
	
	int len_sandstorm = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = d6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = a5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = a5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = b5;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	sandstorm[len_sandstorm++] = e6;
	sandstorm[len_sandstorm++] = 0;
	
	while (1) 
	{
		volatile unsigned down = *(volatile unsigned*)GPIO_PINS;
		
		if ((down & KEY1) == 0) 
		{
			play_song(sandstorm, len_sandstorm);
		} 

		else if ((down & KEY3) == 0)
		{
			play_song(soviet, len_soviet);
		}
	}
}
