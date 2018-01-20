#include "TermMonitor.Class.hpp"

TermMonitor::TermMonitor() : _ch(0) {
	initscr();
	noecho();
	curs_set(0);
	timeout(0);
	keypad(stdscr,TRUE);
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	resize();
	config();
	clear();
	run();
}

TermMonitor::TermMonitor(TermMonitor const &cc)
{
    *this = cc;
}

TermMonitor::~TermMonitor(){
	endwin();
}

TermMonitor &TermMonitor::operator=(TermMonitor const &input)
{
    modules_to_display = input.modules_to_display;
	return (*this);
}

void TermMonitor::config(void)
{
	std::string configMes = "Please configure TermMonitor";

	drawBorder();
    mvprintw(_rows/2, (_cols/2 - configMes.length() / 2), "%s", configMes.c_str());
	while (1)
	{
		if ((_ch = getch()) == 10)
			break;
	}
}

void TermMonitor::run(void)
{
	clock_t now = 0;
	clock_t last_sec = 0;

	while (1)
	{
		now = clock();
		if (now / CLOCKS_PER_SEC != last_sec / CLOCKS_PER_SEC && clear())
			last_sec = now;
		resize();
		update();
		print();
		drawBorder();
		if ((_ch = getch()) == 27)
			break;
		while (clock() / CLOCKS_PER_FRAME == now / CLOCKS_PER_FRAME) {};
	}
}

void TermMonitor::update(void)
{
	dtm.update();
	cpum.update();
	ramm.update();
	ntm.update();
}

void TermMonitor::print(void)
{
	int lines = 1;
	mvprintw(lines,1,"You are running the TermMonitor");
	lines += 1;
	mvprintw(lines,1,"%s",nm.getInfo().c_str());
	lines += nm.getVisSize();
	mvprintw(lines,1,"%s",osim.getInfo().c_str());
	lines += osim.getVisSize();
	mvprintw(lines,1,"%s",dtm.getInfo().c_str());
	lines += dtm.getVisSize();
	mvprintw(lines,1,"%s",cpum.getInfo().c_str());
	lines += cpum.getVisSize();
	mvprintw(lines,1,"%s",ramm.getInfo().c_str());
	lines += ramm.getVisSize();
	mvprintw(lines,1,"%s",ntm.getInfo().c_str());
}

void TermMonitor::resize(void)
{
	getmaxyx(stdscr, _rows, _cols);
}

void TermMonitor::drawBorder(void)
{
	attron(COLOR_PAIR(1));
	wborder(stdscr, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER,
			ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
	attroff(COLOR_PAIR(1));
}
