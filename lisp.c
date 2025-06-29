/*The MIT License (MIT)

Copyright © 2025 Artem Podlegaev 


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE. */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <editline.h>

#define SCAN_BUFFER 1024

#define PROMT_STRING ">>"

const int EXIT = 0, O_PLUS = 1, O_MINUS = 2, O_MUL = 3, O_DIV = 4;


const int is_keyword(const char* in) {
	if (strcmp(in, "+") == 0) return O_PLUS;
	if (strcmp(in, "-") == 0) return O_MINUS;
	if (strcmp(in, "*") == 0) return O_MUL;
	if (strcmp(in, "/") == 0) return O_DIV;
	
	return EXIT;
}

void scan(char* input) {
	printf("%s\n", input);
	
	for (int i = 0; i < sizeof(input); ++i) {
		if (isdigit(input[i])) {
			int digit = input[i] - '0';
			int j = i;
			while (isdigit(input[j]) && isdigit(input[j + 1]) && input[j] != ' ') {
					digit = (digit * 10) + (input[j] -'0');
					++j;
			}
			i = j;
			printf("%d\n", digit);
		}
		else if (isalpha(input[i])) {
			char lexem[100] = {0};
			int pos = 0;
			int j = i;
			while (isalpha(input[j])) {
				lexem[pos++] = input[j];
				++j;
			}
			lexem[pos] = '\0';
			i = j - 1;
			printf("%s\t", lexem);
			printf("%d\n", is_keyword(lexem));
		}
		else if (isspace(input[i])) {
			continue;
		}
		else {
			char symbol[2] = {input[i], '\0'};
			printf("%s\t", symbol);
			printf("%d\n", is_keyword(symbol));
		}
	}
}

int main() {
	puts("Lisp version 0.0.1\n");
	puts("Press Ctrl+d to exit\n");

	while (1) {
		char* input = readline(PROMT_STRING);
		scan(input);
		if (!input) {
			printf("\n");
			return 0;
		}
	}
} 
