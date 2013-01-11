all:
	gcc -Wall -o otp otp.c
	gcc -Wall -o unotp unotp.c
debug:
	gcc -Wall -g -o otp otp.c
	gcc -Wall -g -o unotp unotp.c
clean:
	rm -rf otp
	rm -rf unotp
install:
	cp otp /usr/local/bin/otp
	cp unotp /usr/local/bin/unotp
uninstall:
	rm -rf /usr/local/bin/otp
	rm -rf /usr/local/bin/unotp
