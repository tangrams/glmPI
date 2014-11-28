EXE = app.out

SOURCES := $(wildcard src/*.cpp) $(wildcard src/view/*.cpp) $(wildcard src/util/*.cpp)
HEADERS := $(wildcard src/*.cpp)  $(wildcard src/view/*.cpp) $(wildcard src/util/*.h)
OBJECTS := $(SOURCES:.cpp=.o)

INCLUDES+=-I$(SDKSTAGE)/opt/vc/include/ -I$(SDKSTAGE)/opt/vc/include/interface/vcos/pthreads -I$(SDKSTAGE)/opt/vc/include/interface/vmcs_host/linux -Isrc/ -Iinclude/

CFLAGS+= -std=c++11 -Wall -g \
	 -DPLATFORM_RPI \
	 -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM \
	 -Wno-psabi -fpermissive

LDFLAGS+=-L$(SDKSTAGE)/opt/vc/lib/ \
		-lGLESv2 -lEGL \
		-lbcm_host \
		-lvcos \
		-lvchiq_arm \
		-lrt

all: $(EXE)

%.o: %.cpp
	@echo $@
	$(CXX) $(CFLAGS) $(INCLUDES) -g -c $< -o $@ -Wno-deprecated-declarations

$(EXE): $(OBJECTS) $(HEADERS)
	$(CXX) -o $@ -Wl,--whole-archive $(OBJECTS) $(LDFLAGS) -Wl,--no-whole-archive -rdynamic

clean:
	@rm -rvf $(EXE) src/*.o src/view/*.o src/util/*.o

install:
	@cp $(EXE) /usr/local/bin

uninstall:
	@rm /usr/local/bin/$(EXE)
