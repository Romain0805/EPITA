#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <err.h>

struct field {
    char *title;
    char *artist;
    char *year;
};

static struct option long_options[] = {
            {"artist", required_argument, NULL, 'a'},
            {"year",  required_argument, NULL,  'y' },
            {0, 0, 0, 0 }
        };

int main(int argc, char **argv)
{
    struct field test = {
        NULL, NULL, NULL
    };
    int c = 0;
    while ((c = getopt_long(argc, argv, "a:y:z",
    long_options, NULL)) != -1)
    {
        switch (c)
        {
        case 'a':
          test.artist = optarg;
          break;

        case 'y':
          test.year = optarg;;
          break;
        case '?':
          return 1;
          break;
        }
    }
    if (argc > optind)
    {
        printf("Song name: %s\n", argv[optind]);
    }
    else
    {
        warnx("missing song title");
        return 1;
    }
    if (test.artist)
        printf("By: %s\n", test.artist);
    if (test.year)
        printf("Year: %s\n", test.year);
    return 0;
}