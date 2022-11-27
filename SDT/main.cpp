#include "Parser.c"

//File* sourceFile;

int main(int argc, char* argv[]) {
	printf("[start of SDT program]\n"); // open file

	sourceFile = fopen(argv[1], "r");
	if (sourceFile == NULL) {
		printf("sourceFile open error\n");
		exit(1);
	}
	printf("open file name: %s\n", argv[1]);

	char resultFile[50] = "";
	strcat(resultFile, argv[1]);
	strcat(resultFile, "_result.txt"); // generate AST result file

	astFile = fopen(resultFile, "w");
	if (sourceFile == NULL) {
		printf("astFile open error\n");
		exit(1);
	}
	printf("generated file name: %s\n", resultFile);

	Node* root = parser(); // 가장 윗단 파서 시작 루트를 달음

	printTree(root, 2);
	printf("\n[End of program execution]\n");

	return 0;
}