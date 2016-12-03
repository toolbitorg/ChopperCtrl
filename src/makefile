CXX = $(shell wx-config --cxx)
WX-CONFIG_CXXFLAGS	= -I../include $(shell wx-config --cxxflags)
WX-CONFIG_LIBS		= $(shell wx-config --libs)


PROGRAM	= ChopperCtrl.exe
OBJECTS	= main.o chopper_ctrl.o

# implementation

.SUFFIXES:      .o .cpp

.cpp.o :
	$(CXX) -c $(WX-CONFIG_CXXFLAGS) -o $@ $<

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) $(WX-CONFIG_LIBS)

clean:
	rm -f *.o $(PROGRAM)