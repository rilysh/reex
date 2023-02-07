ifndef CC
	$(error No C compiler found, please make sure the compiler is in env path with CC key)
endif

PROGRAM=reex
LIBS=-pthread
FLAGS=-msse -msse2 -mavx
# OPTMZ=-O2
# If your CPU don't support SSE or SSE2 or AVX, enabling optimizating,
# GCC or Clang will fall back and will use normal calculation method.
# You can turn off AVX, however, I didn't add the same for SSE2, so if your
# CPU doesn't support SSE2, you can enable optimization and avoid using "--mix-sse2-dp"
# and "--eall" commands. You may also need to opt-out "-msse2" flag too. 

all:
	$(CC) $(PROGRAM).c -o $(PROGRAM) $(LIBS) $(FLAGS)

clean:
	rm $(PROGRAM)
