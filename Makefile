TARGETS	=	project

all:		$(TARGETS)

project:		TestDriver.o  Book.o ClubMember.o BkArray.o CmArray.o BookClub.o Control.o View.o Rating.o
	g++ -o		project	 TestDriver.o	 Book.o ClubMember.o BkArray.o CmArray.o BookClub.o Control.o View.o Rating.o

TestDriver.o:		TestDriver.cc Book.h ClubMember.h BkArray.h CmArray.h BookClub.h Control.h View.h Rating.h
	g++ -c TestDriver.cc

Book.o:		Book.cc	Book.h
	g++ -c Book.cc

ClubMember.o:		ClubMember.cc		ClubMember.h
	g++ -c ClubMember.cc

BkArray.o:		BkArray.cc		BkArray.h
	g++ -c BkArray.cc

CmArray.o:		CmArray.cc		CmArray.h
	g++ -c CmArray.cc

BookClub.o:		BookClub.cc		BookClub.h
	g++ -c BookClub.cc

Control.o:		Control.cc		Control.h
	g++ -c Control.cc

View.o:		View.cc		View.h
	g++ -c View.cc

Rating.o:	Rating.cc		Rating.h
	g++ -c Rating.cc

clean:$
	rm -f *.o project
