//THIS WILL BE MY FIRST INDIVIDUAL PROJECT USINF C++
#include<iostream>
#include<SDL.h>
#include"Window.h"
#include "Rect.h"
#include "Text.h"
#include<stdlib.h>
#include<time.h>
#include<string>
#include "Data.h"
#include<sstream>
#include<stdio.h>
#include"Input.h"
#include "Mouse.h"
using namespace std;

void pollEvent(Window& window, Rect& rect, Rect& next, Rect& easy, Rect& medium, Rect& hard, Rect& keep_playing, Rect& view_score) {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		rect.pollEvents(window, event);
		next.pollEvents(window, event);
		easy.pollEvents(window, event);
		medium.pollEvents(window, event);
		hard.pollEvents(window, event);
		keep_playing.pollEvents(window, event);
		view_score.pollEvents(window, event);


		if (event.type == SDL_QUIT) {
			exit(0);
			SDL_StopTextInput();
			TTF_Quit();
			IMG_Quit();
			SDL_Quit();
		}
	}
}

int main(int argc, char* argv[]) {
	srand(time(NULL));
	Window window("hamza_ window", 800, 600);
	// from now we are going to work just with mouse events.
	while (window._closed == false)
	{
		Rect rect(100, 200, 400, 300, "res/start.png");
		Rect background(600, 800, 400, 300, "res/background.png");
		Rect next(100, 200, 400, 300, "res/next.png");
		Rect easy(100, 200, 150, 300, "res/easy.png");
		Rect medium(100, 200, 400, 300, "res/medium.png");
		Rect hard(100, 200, 650, 300, "res/hard.png");
		Rect keep_playing(100, 200, 200, 300, "res/keep_playing.png");
		Rect view_score(100, 200, 600, 300, "res/score.png");

		SDL_Event event;
		window.pollEvents(event);
		///////////the pricipal enter will be a loop until you click
		background.draw();
		window.clear();
		while (!rect.end) {
			background.draw();
			rect.draw();
			window.clear();
			pollEvent(window, rect, next, easy, medium, hard, keep_playing, view_score);
		}

		background.draw();
		window.clear();


		keep_playing.end = false;
		view_score.end = false;
		medium.end = 0;
		hard.end = 0;
		easy.end = 0;
		Text Diff_level(Window::renderer, "res/3d.ttf", 40, "chose your difficulty level-:", { 0,0,255,255 });
		while ((medium.end == false) && (easy.end == false) && (hard.end == false)) {
			background.draw();
			Diff_level.display(50, 150, Window::renderer);
			easy.draw();
			medium.draw();
			hard.draw();
			pollEvent(window, rect, next, easy, medium, hard, keep_playing, view_score);
			window.clear();
		}
		int score_ps = 0;
		int score_pp = 0;
		char buf[50]{ 0 };

		bool loop_runnig = true;
		bool firs_loop_verb = 1;
		bool firs_loop_past_simple = 1;
		bool second_loop_verb = 1;
		bool firs_loop_past_participle = 1;
		//---------------------------------------------
		int *r =nullptr ;
		int e = 0;
		int m = 0;
		int h = 0;
		//set up our r  conditions 
		if (easy.end == true) {
			r = &e;
		}
		else if (medium.end == true) {
			r = &m;
		}
		else if (hard.end == true) {
			r = &h;
		}
		//----------------------
		while (loop_runnig) {

			background.draw();
			window.clear();

			 firs_loop_verb = 1;
			 firs_loop_past_simple = 1;
			 second_loop_verb = 1;
			 firs_loop_past_participle = 1;

			sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
			e = rand() % 101;
			m = rand() % 148 + 101;
			h = rand() % 48 + 249;
			Data data((*r));

			Input input1;
			string past_simple = "";
			Text your_verb(Window::renderer, "res/insane.ttf", 30, "your verb is:", { 0,255,255,255 });
			Text verb(Window::renderer, "res/mer.ttf", 40, data.loadData("v"), { 0,255,0,255 });
			while (true)
			{// all thid loop is for treating the verb and it's events
				Text score(Window::renderer, "res/insane.ttf", 30, buf, { 255,0,0,255 });//score output
				while (firs_loop_verb) {//waiting to display
					background.draw();
					your_verb.display(120, 150, Window::renderer);
					verb.display(380, 150, Window::renderer);
					score.display(300, 500, Window::renderer);
					window.clear();
					SDL_Delay(1000);
					firs_loop_verb = 0;
				}
				background.draw();
				score.display(300, 500, Window::renderer);
				your_verb.display(120, 150, Window::renderer);
				verb.display(380, 150, Window::renderer);
				Text enter_ps(Window::renderer, "res/insane.ttf", 30, "ENTER THE PAST SIMPLE:", { 255,0,0,255 });
				enter_ps.display(100, 200, Window::renderer);
				input1.pollEvents(event, past_simple);
				if (input1.k && past_simple.length() > 0) {
					input1.display(past_simple, Window::renderer);
				}

				if ((past_simple == data.loadData("ps")) && (!input1.k) && past_simple.length() > 1) {
					Text congrats(Window::renderer, "res/3d.ttf", 50, "congratulations!", { 0,255,0,255 });
					congrats.display(100, 250, Window::renderer);
					score_ps++;
					sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
					Text score_ps(Window::renderer, "res/insane.ttf", 30, buf, { 255,0,0,255 });//score output
					score_ps.display(300, 500, Window::renderer);
					window.clear();
					SDL_Delay(1000);
					rect.end = 0;
					break;
				}
				else if ((past_simple == data.loadData("ps2")) && (!input1.k) && past_simple.length() > 1) {
					Text congrats(Window::renderer, "res/3d.ttf", 50, "congratulations!", { 0,255,0,255 });
					congrats.display(100, 250, Window::renderer);
					score_ps++;
					sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
					Text score_ps2(Window::renderer, "res/insane.ttf", 30, buf, { 255,0,0,255 });//score output
					score_ps2.display(300, 500, Window::renderer);
					window.clear();
					SDL_Delay(1000);
					rect.end = 0;
					break;
				}
				else if ((past_simple != data.loadData("ps")) && (past_simple != data.loadData("ps2")) && (!input1.k) && past_simple.length() > 1) {
					Text wrong(Window::renderer, "res/3d.ttf", 50, "wrong answer!", { 0,255,0,255 });
					Text past_s(Window::renderer, "res/mer.ttf", 70, data.loadData("ps"), { 0,0,255,255 });
					Text the_correct(Window::renderer, "res/insane.ttf", 30, "THE CORRECT ANSWER IS:", { 100,100,200,255 });
					wrong.display(100, 250, Window::renderer);
					while (firs_loop_past_simple) {//waiting to display
						background.draw();
						wrong.display(100, 250, Window::renderer);
						window.clear();
						SDL_Delay(2000);
						firs_loop_past_simple = 0;
					}

					background.draw();
					Text score_nps(Window::renderer, "res/insane.ttf", 30, buf, { 255,0,0,255 });//score output
					score_nps.display(300, 600, Window::renderer);
					the_correct.display(100, 200, Window::renderer);
					past_s.display(450, 200, Window::renderer);
					window.clear();
					SDL_Delay(2000);
					rect.end = 0;
					past_simple = "";
					break;
				}
				
				window.clear();
			}
			////
			sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
			next.end = 0;
			while (!next.end) {
				Text score(Window::renderer, "res/insane.ttf", 30, buf, { 255,0,0,255 });//score output
				background.draw();
				score.display(300, 500, Window::renderer);
				next.draw();
				window.clear();
				//next.pollEvents(window, event);
				pollEvent(window, rect, next, easy, medium, hard, keep_playing, view_score);
			}
			///
			//----------------------------------------------PAST PARTICIPLE
			Input input2;
			string past_participle = "";
			while (true) {// all thid loop is for treating the verb and it's events
				Text score2(Window::renderer, "res/insane.ttf", 30, buf, { 255,0,0,255 });//score2 output	
				while (second_loop_verb) {//waiting to display
					background.draw();
					your_verb.display(120, 150, Window::renderer);
					verb.display(380, 150, Window::renderer);
					score2.display(300, 500, Window::renderer);
					window.clear();
					SDL_Delay(1000);
					second_loop_verb = 0;
				}
				background.draw();
				score2.display(300, 500, Window::renderer);
				your_verb.display(120, 150, Window::renderer);
				verb.display(380, 150, Window::renderer);
				Text enter_pp(Window::renderer, "res/insane.ttf", 30, "ENTER THE PAST PARTICIPLE:", { 255,100,0,255 });
				enter_pp.display(100, 200, Window::renderer);
				input2.pollEvents(event, past_participle);

				if (input2.k && past_participle.length() > 0) {
					input2.display(past_participle, Window::renderer);
				}

				if ((past_participle == data.loadData("pp")) && ((!input2.k)) && (past_participle.length() > 2)) {
					Text congrats(Window::renderer, "res/3d.ttf", 60, "Congratulations!!", { 0,255,0,255 });
					congrats.display(100, 250, Window::renderer);
					score_pp++;
					sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
					Text score_pp(Window::renderer, "res/insane.ttf", 30, buf, { 255,0,0,255 });//score output
					score_pp.display(300, 500, Window::renderer);
					window.clear();
					SDL_Delay(2000);
					next.end = 0;
					past_participle = "";
					break;
				}

				else if ((past_participle == data.loadData("pp2")) && (!input2.k) && (past_participle.length() > 2)) {
					Text congrats(Window::renderer, "res/3d.ttf", 50, "Congratulations!!", { 0,255,0,255 });
					congrats.display(100, 250, Window::renderer);
					score_pp++;
					sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
					Text score_pp2(Window::renderer, "res/insane.ttf", 30, buf, { 0,255,0,255 });//score output
					score_pp2.display(300, 500, Window::renderer);
					window.clear();
					SDL_Delay(2000);
					next.end = 0;
					past_participle = "";
					break;
				}

				else if ((past_participle != data.loadData("ps")) && (!input2.k) && (past_participle.length() > 1)) {
					Text wrong(Window::renderer, "res/3d.ttf", 50, "wroooong answer", { 0,255,0,255 });
					Text past_p(Window::renderer, "res/mer.ttf", 70, data.loadData("pp"), { 0,0,255,255 });
					Text the_correct(Window::renderer, "res/insane.ttf", 30, "THE CORRECT ANSWER IS:", { 255,100,100,255 });
					wrong.display(100, 250, Window::renderer);
					while (firs_loop_past_participle) {//waiting to display
						background.draw();
						wrong.display(100, 250, Window::renderer);
						window.clear();
						SDL_Delay(1000);
						firs_loop_past_participle = 0;
					}
					background.draw();
					the_correct.display(100, 200, Window::renderer);
					past_p.display(450, 200, Window::renderer);
					sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
					Text score_npp(Window::renderer, "res/insane.ttf", 30, buf, { 0,0,255,255 });//score output
					score_npp.display(300, 500, Window::renderer);
					window.clear();
					SDL_Delay(2000);
					past_participle = "";
					break;
				}
				sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
				window.clear();
			}//past participle
			sprintf_s(buf, sizeof(buf), "score:  ps= %d pp=%d ", score_ps, score_pp);
			SDL_Delay(1000);
			//________________________________________

			keep_playing.end = false;
			view_score.end = false;
			while ((keep_playing.end == false) && (view_score.end == false)) {
				background.draw();
				keep_playing.draw();
				view_score.draw();
				pollEvent(window, rect, next, easy, medium, hard, keep_playing, view_score);
				window.clear();
			}

			if (view_score.end == true) {
				background.draw();
				Text score_final(Window::renderer, "res/insane.ttf", 70, buf, { 100,100,255,255 });//score output
				score_final.display(100, 250, Window::renderer);
				window.clear();
				SDL_Delay(2000);
				loop_runnig = false;
			}
			else if (keep_playing.end == true) {
				loop_runnig = true;
			}
			//window.clear();
		}

		//window.clear();
	}
	return 0;
}
//very cool though now we can do what ever we want we are on the waay hooomiiizzzzz