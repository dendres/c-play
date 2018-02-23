#include <stdio.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <criterion/criterion.h>

/* x.x.x.x where x in 0-255, zero padding is invalid */
int is_valid_ip(const char * addr)
{

        struct sockaddr_in sockaddr;
        return inet_pton(AF_INET, addr, &(sockaddr.sin_addr)) ? 1 : 0;

        /*
        int i, j, x;
        char *o;
        char **octet = malloc(4 * sizeof(char*));
        char *address = malloc(sizeof(addr));

        strcpy(address, addr);
        octet[0] = strtok(address, ".");
        for (i = 1; i < 4; i++) {
                octet[i] = strtok(NULL, ".");
        }
        if (strtok(NULL, ".")) return 0;

        for(i = 0; i < 4; i++) {
                o = octet[i];
                if (o == NULL) return 0;

                for (j = 0; o[j] != '\0'; j++) {
                        if (!isdigit(o[j])) return 0;
                }

                if (o[0] && o[1] && o[0] == '0') return 0;

                x = (int)strtol(o,(char **)NULL, 10);

                if (x < 0 || x > 255) return 0;
        }

        printf("%s,%s,%s,%s\n", octet[0], octet[1], octet[2], octet[3]);

        free(octet);
        free(address);

        return 1;
        */
}


Test(is_valid_ip, example_tests) {
        cr_expect_eq(is_valid_ip("12.255.56.1"), 1, "\"%s\" IS a valid IP", "12.255.56.1");
        cr_expect_eq(is_valid_ip(""), 0, "\"%s\" IS a valid IP", "");
        cr_expect_eq(is_valid_ip("abc.def.ghi.jkl"), 0, "\"%s\" IS a valid IP", "abc.def.ghi.jkl");
        cr_expect_eq(is_valid_ip("123.456.789.0"), 0, "\"%s\" IS a valid IP", "123.456.789.0");
        cr_expect_eq(is_valid_ip("12.34.56"), 0, "\"%s\" IS a valid IP", "12.34.56");
        cr_expect_eq(is_valid_ip("12.34.56 .1"), 0, "\"%s\" IS a valid IP", "12.34.56 .1");
        cr_expect_eq(is_valid_ip("12.34.56.-1"), 0, "\"%s\" IS a valid IP", "12.34.56.-1");
        cr_expect_eq(is_valid_ip("123.045.067.089"), 0, "\"%s\" IS a valid IP", "123.045.067.089");
        cr_expect_eq(is_valid_ip("1.2.3.4.5"), 0, "\"%s\" IS a valid IP", "1.2.3.4.5");
}
