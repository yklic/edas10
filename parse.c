#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char **argv) {
  int ch;
  char * words;
  FILE * fp;
  char * infile, * outfile;

  int opt;
  int opt_idx;
  char * opstr = "i:o:";
  static struct option loptstr[] = {
    {"in",  required_argument, NULL, 'i'},
    {"out", required_argument, NULL, 'o'}
  };

  if ( argc != 5 ) {
    printf("Usage: fieldsolver2d -in input.data –out result.out\n");
    exit(EXIT_FAILURE);
  }

  while ((opt = getopt_long_only(argc, argv, opstr, loptstr, &opt_idx)) != -1) {
    printf("opt = %c\t\t", opt);
    printf("optarg = %s\t\t", optarg);
    printf("optind = %d\t\t", optind);
    printf("argv[optind] = %s\t\t", argv[optind]);
    printf("option_index = %d\n", opt_idx);
    if (opt == 'i') {
      infile = optarg;
    } else {
      outfile = optarg;
    }
  }
  printf("infile: %s\n", infile);
  printf("outfile: %s\n", outfile);

  if ((fp = fopen(infile, "r")) == NULL) {
    printf("Failed to open the input data!\n");
    exit(EXIT_FAILURE);
  }

  while ((ch = getc(fp)) != EOF) {
    printf("%c", ch);
  }

  rewind(fp);
  
  while (fscanf(fp, "%s", words) == 1) {
    printf("%s\n", words);
  }

  fclose(fp);

  return 0;
}
