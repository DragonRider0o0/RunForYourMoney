#include <pebble.h>
 
Window *window;
//TextLayer *text_layer;


BitmapLayer *splash_layer;

typedef enum {
    SPLASH = 0,
    HOME = 1,
    CURRENT = 2,
    NEW = 3,
	   OLD = 4,
	   SETTINGS = 5,
	   START = 6,
	   RACE = 7,
	   STATS = 8,
	   PAST_RACE = 9
} screen;

void splash_window(Window *window)
	{
	 GBitmap *tiny_bitmap;
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
 	GBitmap *splash_bitmap;
	 splash_bitmap= gbitmap_create_with_resource(RESOURCE_ID_SPLASH);
	 splash_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(splash_layer, splash_bitmap);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(splash_layer));
}

void home_window(Window *window)
{
	 GBitmap *tiny_bitmap;
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);

	 MenuLayer* mainMenu;
	
}

void drawWindow(screen target, Window *window)
{
			switch(target){
    case SPLASH: splash_window(window); return;
    case HOME: printf("zero"); return;
    case CURRENT: printf("pos inf"); return;
				case NEW: printf("pos inf"); return;
				case OLD: printf("pos inf"); return;
				case SETTINGS: printf("pos inf"); return;
				case START: printf("pos inf"); return;
				case RACE: printf("pos inf"); return;
				case STATS: printf("pos inf"); return;
				case PAST_RACE: printf("pos inf"); return;
    default: printf("not special"); break;
}
  
	
	
	
}

void window_load(Window *window)
{
	  drawWindow(SPLASH, window);
  //window_set_fullscreen(window, true);
  //We will add the creation of the Window's elements here soon!
  //text_layer = text_layer_create(GRect(0, 0, 144, 168));
  //text_layer_set_background_color(text_layer, GColorClear);
  //text_layer_set_text_color(text_layer, GColorBlack);
 
  //layer_add_child(window_get_root_layer(window), text_layer_get_layer(text_layer));
	 //text_layer_set_text(text_layer, "Run For Your Money!");
	 //tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 //	window_set_status_bar_icon	(window, tiny_bitmap);
 	//splash_bitmap = gbitmap_create_with_resource(RESOURCE_ID_SPLASH);
	 //splash_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  //bitmap_layer_set_bitmap(splash_layer, splash_bitmap);
  //layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(splash_layer));
}
 
void window_unload(Window *window)
{
  //We will safely destroy the Window's elements here!
 	//text_layer_destroy(text_layer);
	 //Destroy GBitmaps
  gbitmap_destroy(splash_bitmap);
 
  //Destroy BitmapLayers
  bitmap_layer_destroy(splash_layer);
}
 
void init()
{
  //Initialize the app elements here!
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	window_stack_push(window, true);
}
 
void deinit()
{
  //De-initialize elements here to save memory!
	 window_destroy(window);
}
 
int main(void)
{
  init();
  app_event_loop();
  deinit();
}

