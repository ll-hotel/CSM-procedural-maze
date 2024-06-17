#ifndef APP_H
# define APP_H

# include <SDL2/SDL.h>
# include <string>

class App {
public:
	App(void);
	App(const App&);
	~App(void);

	int init(void);
	int execute(void);
	void render(void);
	void on_event(const SDL_Event &);
	void loop(void);
	void cleanup(void);
	static int log(std::string);

	int window_width;
	int window_height;
	SDL_Window *window;
	SDL_Surface *surface;
	SDL_Renderer *renderer;
	int running;
};

#endif
