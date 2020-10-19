#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define MAX_NUMBERS_SIZE 100
#define FROM_STR "--from="
#define TO_STR "--to="

int main(int argc, char** argv) {
		if (argc < 2)
		{
			return -1;
		}
		else if (argc > 3)
		{
			return -2;
		}

		long long from_value = 0, to_value = 0;
		int from_count = 0, to_count = 0;
		for (int i = 0; i < argc; i++) {
			if (strncmp(argv[i], FROM_STR, strlen(FROM_STR)) == 0)
			{
				from_value = strtoll(argv[i] + strlen(FROM_STR), NULL, 10);
				from_count += 1;
			}
			else if (strncmp(argv[i], TO_STR, strlen(TO_STR)) == 0)
			{
				to_value = strtoll(argv[i] + strlen(TO_STR), NULL, 10);
				to_count += 1;
			}
		}
		if (from_count > 1 || to_count > 1)
		{
			return -3;
		}
		else if (from_count == 0 && to_count == 0)
		{
			return -4;
		}

		long long input[MAX_NUMBERS_SIZE];
		long long input_check[MAX_NUMBERS_SIZE];
		int input_count = 0;
		for (int k = 0; k < MAX_NUMBERS_SIZE; k++) {

			long long input_value;
			char space;

			if (scanf("%lld%c", &input_value, &space) != 2)
			{
				break;
			}

			if (from_count == 1 && input_value <= from_value)
			{
				fprintf(stdout, "%lld ", input_value);
			}
			else if (to_count == 1 && input_value >= to_value)
			{
				fprintf(stderr, "%lld ", input_value);
			}
			else
			{
				input[input_count] = input_value;
				input_check[input_count] = input_value;
				input_count++;
			}

			if (space != ' ')
			{
				break;
			}
		}
		bubblesort(input, input_count);
		int change_count = 0;

		for (int i = 0; i < input_count; i++)
		{
			if (input[i] != input_check[i])
			{
				change_count++;
			}
		}
		printf("\n");

		return change_count;
}