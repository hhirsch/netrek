############################################################################
# System dependend defines, we try to guess this values.
# Change them if we are wrong.
############################################################################

SHELL	= /bin/sh
CC      = gcc
LN	= ln -s

PROTOIZE   = protoize
UNPROTOIZE = unprotoize
INDENT     = indent -i2 -bap -bacc -bad -nbc -bl -nip -di8\
		-npsl -nce -cli0.5 -ci4 -npcs -fca -ncdb -sc -cd50 -c50
TOUCH	   = touch
RM	   = rm -f 

# Directory to find multiprecision library and includes. 
# if you  don't have libmp.a you are probably hosed .. but it's easy to 
# get gmp from the GNU people. 
#

RSA_FLAGS       =  -DRSA
RSASRC          =  rsa_box.c rsa_box_0.c rsa_box_1.c rsa_box_2.c \
		rsa_box_3.c rsa_box_4.c rsa_box_5.c rsa_box_6.c \
		rsa_box_7.c rsa_box_8.c rsa_box_9.c rsa_box_10.c
RSAOBJ          =  rsa_box.o rsa_box_0.o rsa_box_1.o rsa_box_2.o \
                rsa_box_3.o rsa_box_4.o rsa_box_5.o rsa_box_6.o \
		rsa_box_7.o rsa_box_8.o rsa_box_9.o rsa_box_10.o
MPINC           = 
LMP             =   -lgmp

# Other libraries neeeded. (All systems need -lX11 -lm)

LIBS            =   -lXpm -lX11 -lnsl -lm 
INCS		=  

# Flags for optimizing
# (-O, -g, -O2)

OPT             = -g -Wall

# Flags for shared libraries

SL_CFLAGS	= -fPIC
SL_LDFLAGS	= -shared $(LIBRARIES) -lc 
SL_LIB          = libcow.so.`./name 1`
SL_LIBFLAGS	= -Wl,-soname,$(SL_LIB)

COWAPI		= cowapi.h
COWLIB		= libcow.so.`./name 1`.`./name 2`.`./name p`
COWDLL		= cow.so

# random.c  Some arches don't have random(), we will compile it if necessary
# set RANDOMOBJ = random.o if you need this, otherwise leave it blank.

RANDOMOBJ       = 

###############################################################################
#  No editables below this point.
###############################################################################


include $(KEYDEF)


ROBJ 		= check.o colors.o data.o death.o defaults.o dmessage.o\
                  enter.o findslot.o getname.o getship.o helpwin.o inform.o\
                  interface.o newwin.o option.o planetlist.o macrowin.o\
	          map.o playerlist.o ranklist.o reserved.o sintab.o\
	          smessage.o socket.o playback.o stats.o util.o war.o warning.o\
	          udpopt.o ping.o pingstats.o rotate.o lagmeter.o parsemeta.o\
	          netstat.o netstatopt.o spopt.o dashboard.o dashboard3.o \
	          short.o distress.o senddist.o defwin.o tools.o sound.o\
		  docwin.o cflags.o beeplite.o feature.o\
		  string_util.o local.o censor.o cowmain.o camera.o myf.o

RSRC 		= check.c colors.c data.c death.c defaults.c dmessage.c\
	          enter.c findslot.c getname.c getship.c helpwin.c inform.c\
	          input.c interface.c newwin.c option.c planetlist.c\
                  macrowin.c map.c playerlist.c ranklist.c redraw.c\
                  smessage.c parsemeta.c socket.c playback.c stats.c util.c war.c\
                  warning.c udpopt.c sintab.c ping.c pingstats.c rotate.c\
                  lagmeter.c netstat.c netstatopt.c spopt.c dashboard.c dashboard3.c \
		  short.c distress.c senddist.c defwin.c tools.c sound.c\
		  docwin.c cflags.c beeplite.c feature.c reserved.c\
		  string_util.c local.c censor.c cowmain.c camera.c myf.c


INCLUDES 	= struct.h packets.h defs.h copyright.h bitmaps.h data.h\
	          oldbitmaps.h tngbitmaps.h hullbitmaps.h rabbitbitmaps.h\
		  sound.h audio.h litebitmaps.h 

INPUTOBJ 	= input.o redraw.o 
MAINOBJ 	= main.o
MAINSRC 	= main.c

X11OBJ	 	=  x11window.o x11sprite.o audio.o
X11SRC		=  x11window.c x11sprite.c audio.c

WIN32OBJ	= # gnu_win32.o winsprite.o winsndlib.o
WIN32SRC	= # gnu_win32.c winsprite.c winsndlib.c

SDL_CFLAGS 	= -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT
SDL_CONFIG 	= /usr/bin/sdl-config
SDL_LIBS 	= -L/usr/lib/i386-linux-gnu -lSDL
SDL_MIXER_LIBS	= -lSDL_mixer

# full screen support
XXF86VM_LIBS    = -lXxf86vm
# camera snapshot support
IMLIB2_LIBS     = $(shell imlib2-config --libs)

SHARED 	= $(SL_CFLAGS)
INCDIRS = $(MPINC) $(INCS)
CFLAGS ?= $(OPT)
CFLAGS += $(EXTRACFLAGS) $(RSA_FLAGS) $(INCDIRS)
LDFLAGS ?= -g
LDFLAGS += $(EXTRALINKFLAGS)
LIBRARIES = $(LMP) $(LIBS) $(EXTRALIBS) $(SDL_LIBS) $(SDL_MIXER_LIBS) $(XXF86VM_LIBS) $(IMLIB2_LIBS)

netrek-client-cow: $(RSAOBJ) $(PMAKE) null $(ROBJ) $(MAINOBJ) $(INPUTOBJ) $(X11OBJ) $(WIN32OBJ)  $(RANDOMOBJ) cflags.c
	$(CC) $(LDFLAGS) -o netrek-client-cow $(ROBJ) $(RSAOBJ) $(INPUTOBJ) \
	$(MAINOBJ) $(X11OBJ) $(WIN32OBJ) $(RANDOMOBJ) $(LIBRARIES)

netrek.shared: done.libcow $(MAINOBJ) $(COWAPI)
	$(CC) $(LDFLAGS) $(MAINOBJ) -L. -lcow $(LIBS) -o netrek.shared

done.libcow: $(PMAKE) $(ROBJ) $(RSAOBJ) $(INPUTOBJ) $(X11OBJ) $(WIN32OBJ) $(RANDOMOBJ) 
	$(CC) $(ROBJ) $(RSAOBJ) $(INPUTOBJ) \
	$(X11OBJ) $(WIN32OBJ) $(RANDOMOBJ) $(SL_LDFLAGS) $(SL_LIBFLAGS) -o $(COWLIB)
	$(RM) $(SL_LIB)
	$(LN) $(COWLIB) $(SL_LIB)
	$(TOUCH) done.libcow

#rsa_box.c: mkkey $(SECKEYFILE)
$(RSASRC): mkkey $(SECKEYFILE)
	-$(RM) $(RSASRC)
	./mkkey -c -k $(SECKEYFILE)
	$(TOUCH) $(RSASRC)
	@echo "int sock = -1;" >>rsa_box_1.c

$(SECKEYFILE):
	@echo generating a new client key
	$(MAKE) newkey

mkkey: mkkey.c $(RANDOMOBJ) defs.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) $(MPINC) $(MPLIB) -o mkkey mkkey.c $(RANDOMOBJ) $(LIBRARIES)

randomize: randomize.c $(RANDOMOBJ) defs.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o randomize randomize.c $(RANDOMOBJ) $(LIBRARIES)

sound.o: sound.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SDL_CFLAGS) -c sound.c

random.o: random.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c random.c

strdup.o: strdup.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c strdup.c

cflags.c: mkcflags
	./mkcflags "$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS)" "$(ARCH)"  > cflags.c
	echo char cwho[]=$(CWHO)\; >> cflags.c

mkcflags: mkcflags.c system.mk null patchlevel.h version.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o mkcflags mkcflags.c $(LIBRARIES)

tags: $(RSRC) $(RSASRC)
	ctags $(RSRC) $(RSASRC) $(INCLUDES)

depend: cflags.c null $(RSASRC)
	-makedepend -f system.mk $(RSA_FLAGS) $(RSRC) $(RSASRC) $(MAINSRC) \
	$(X11SRC) name.c $(INCDIRS)

proto: cflags.c null $(RSASRC)
	$(PROTOIZE) $(RSRC) $(MAINSRC) $(X11SRC) $(WIN32SRC)

unproto: cflags.c null $(RSASRC)
	$(UNPROTOIZE) $(RSRC) $(MAINSRC) $(X11SRC) $(WIN32SRC)

indent: cflags.c null $(RSASRC)
	$(INDENT) $(RSRC) $(MAINSRC) $(INCLUDES) $(X11SRC) $(WIN32SRC)

to_unix: $(RSRC) $(INCLUDES) $(MAINSRC) $(X11SRC)
	-for f in $(RSRC) $(INCLUDES) $(MAINSRC) $(X11SRC) $(WIN32SRC) ; do \
	mv $${f} $${f}.bak ; win32/uncr < $${f}.bak > $${f} ;\
	done

to_dos: $(RSRC) $(INCLUDES) $(MAINSRC) $(X11SRC) $(WIN32SRC)
	-for f in $(RSRC) $(INCLUDES) $(MAINSRC) $(X11SRC) $(WIN32SRC) ; do \
	mv $${f} $${f}.bak ; win32/cr < $${f}.bak >$${f} ;\
	done

null:
	@echo "/* This file is intentionally empty */" >null

xtrekrc:
	@grep '^int' data.c \
	| grep '=' \
	| sed -e 's/;.*//' \
	| awk 'NF==4{print $$2,$$4}' > xtrekrc.tmp
	@egrep '(booleanDefault|intDefault)' $(RSRC) $(MAINSRC) $(X11SRC) $(WIN32SRC) \
	| grep  '\"' \
	| sed -e '{s/[(]/ /g;s/[)]/ /g;s/\"//;s/\"/:/;s/, */ /;s/ *;.*//;}' \
	      -e '/intDefault/{s/^.*intDefault */<int> /;}' \
	      -e '/booleanDefault/{s/^.*booleanDefault */<bool> /;}' \
	| awk 'NF==3{print $$3,$$2,$$1}' >> xtrekrc.tmp
	@sort -u xtrekrc.tmp \
	| awk 'NF==2{var=$$1;value=$$2} \
	       NF==3{if (length($$1)<=2)\
			{print "#	"$$2,$$1}\
		     else if (var==$$1)\
			{print "#	"$$2,value}\
		     else\
			{print "#	"$$2,$$3};}' > xtrekrc.tmp1
	@grep 'getdefault' $(RSRC) $(MAINSRC) $(X11SRC) $(WIN32SRC) \
	| grep  '\"' \
	| sed -e '{s|^.*getdefault[^\"]*\"|#	|;s|\".*|: <string>|;}' \
	>> xtrekrc.tmp1
	@echo '# Automatic created xtrekrc with default values' \
	> xtrekrc
	@sort -u xtrekrc.tmp1\
	>> xtrekrc
	-$(RM) xtrekrc.tmp*

# DO NOT DELETE THIS LINE -- make depend depends on it.

