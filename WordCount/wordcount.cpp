#include<stdio.h>
#include<string.h>
int main(int argc, char** argv){
	if (argc < 3){
		printf("error!\n");
		printf("-c:the number of character\n");
		printf("-w:the number of words\n");
		return 0;
	}
	if (strcmp("-c", argv[1])==0){
		char str[1024];
		FILE* fp;
		fp = fopen(argv[2], "r");
		if (fp!=NULL){
			int count = 0;
			while (fgets(str, 1024, fp) != NULL){
				int j = 0;
				while (str[j] != '\0'){
					count++;
					j++;
				}
			}
			printf("the number of character:%d\n", count);
		}else{
			printf("open file failed\n");
		}
	}else if (strcmp("-w", argv[1]) == 0){
		char str[1024];
		FILE* fp;
		fp = fopen(argv[2], "r");
		if (fp!= 0){
			int count = 0;
			while (fgets(str, 1024, fp) != NULL){
				int j = 0;
				while (str[j] != '\0'){
					if(str[0] != '\0' && (str[0] == ' ' || str[0] == ',' || str[0] == '.')){
						while (str[j] == ' ' || str[j] == ',' || str[j] == '.') j++;
					}
					if (str[j]!='\0' && (str[j] == ' ' || str[j] == ',' || str[j] == '.')){
						count++;
						while (str[j] == ' ' || str[j] == ',' || str[j] == '.') j++;
					}
					j++;
				}
				if (j != 0) count++;
			}
			printf("the number of words:%d\n", count);
		}else{
			printf("open file failed\n");
		}
	}else{
		printf("error!\n");
		printf("-c:the number of character\n");
		printf("-w:the number of words\n");
	}
}
