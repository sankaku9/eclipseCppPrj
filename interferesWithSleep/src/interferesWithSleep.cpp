#define _WIN32_WINDOWS 0x0410

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

int main(int argc, char *argv[])

{
	int defDist = 0;
	int dist = 0;
	int i = 0;
	int tmpTimer = 0;
	time_t timer;

	defDist = 3600000;
	if(argc == 2){
		dist = atol(argv[1]);
		printf("%s [%u] %s", "���͂��ꂽ�l��",dist , "�ł�\n");
		defDist = dist*1000*60;
	}else{
		printf("�f�t�H���g�ݒ�\n");
	}

	printf("%u%s", defDist/1000/60, "���ԃX���[�v�}�~�B\n");

	for(i=0 ;i<defDist/30000 ;i++ ) {
		SetThreadExecutionState(ES_SYSTEM_REQUIRED);
		tmpTimer = i*30/60;
		time(&timer);
		printf("%u���o��/%u�� : %s\n", tmpTimer, defDist/1000/60, ctime(&timer));
		fflush(0);
		Sleep(30000);
	}

	return 0;

}
