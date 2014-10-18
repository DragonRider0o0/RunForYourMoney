#include <pebble.h>

	//Universal Elements
	#define	NUM_MENU_SECTIONS 1
Window *window;
static  GBitmap *tiny_bitmap;
typedef enum {
    SPLASH = 0,
    HOME = 1,
    ACTIVE = 2,
    NEW = 3,
	   OLD = 4,
	   SETTINGS = 5,
	   START = 6,
	   RACE = 7,
	   STATS = 8,
	   PAST_RACE = 9
} screen;
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];
	
	//Splash Elements
	static GBitmap *splash_bitmap;
	static BitmapLayer *splash_layer;
	
// Home Elements
#define NUM_HOME_MENU_ITEMS  5
static SimpleMenuLayer* home_menu_layer;
static SimpleMenuItem home_menu_items[NUM_HOME_MENU_ITEMS];


// Active Elements
#define NUM_ACTIVE_MENU_ITEMS  4
static SimpleMenuLayer* active_menu_layer;
static SimpleMenuItem active_menu_items[NUM_ACTIVE_MENU_ITEMS];


// New Elements
#define NUM_NEW_MENU_ITEMS  2
static SimpleMenuLayer* new_menu_layer;
static SimpleMenuItem new_menu_items[NUM_NEW_MENU_ITEMS];


// Old Elements
#define NUM_OLD_MENU_ITEMS  4
static SimpleMenuLayer* old_menu_layer;
static SimpleMenuItem old_menu_items[NUM_OLD_MENU_ITEMS];

// Settings Elements
#define NUM_SETTINGS_MENU_ITEMS  3
static SimpleMenuLayer* settings_menu_layer;
static SimpleMenuItem settings_menu_items[NUM_SETTINGS_MENU_ITEMS];


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void splash_window(Window *window)
	{
	
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
 	
	 splash_bitmap= gbitmap_create_with_resource(RESOURCE_ID_SPLASH);
	 
	 splash_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(splash_layer, splash_bitmap);
  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(splash_layer));
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void home_menu_select_callback(int index, void *ctx) 
{
  home_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(home_menu_layer));
}

void home_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	int num_a_items = 0;
  home_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Start Running",
    .callback = home_menu_select_callback
  };
  home_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Active Challenges",
    .callback = home_menu_select_callback
  };
  home_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "New Challenges",
    .callback = home_menu_select_callback
  };
	  home_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Past Challenges",
    .callback = home_menu_select_callback
  };
		  home_menu_items[num_a_items++] = (SimpleMenuItem)
				{
    .title = "Settings",
    .callback = home_menu_select_callback
  };

  
  menu_sections[0] = (SimpleMenuSection)
		{
			 .title = "RunForYourMoney",
    .num_items = NUM_HOME_MENU_ITEMS,
    .items = home_menu_items,
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  home_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(home_menu_layer));
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void active_menu_select_callback(int index, void *ctx) 
{
  active_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(active_menu_layer));
}

void active_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	int num_a_items = 0;
  active_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Office",
    .callback = active_menu_select_callback
  };
  active_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "New Friends",
    .callback = active_menu_select_callback
  };
  active_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Family",
    .callback = active_menu_select_callback
  };
	  active_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Friends in Italy",
    .callback = active_menu_select_callback
  };
  
  menu_sections[0] = (SimpleMenuSection)
		{
    .num_items = NUM_ACTIVE_MENU_ITEMS,
    .items = active_menu_items,
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  active_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(active_menu_layer));
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void new_menu_select_callback(int index, void *ctx) 
{
  new_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(new_menu_layer));
}

void new_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	int num_a_items = 0;
  new_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Join Challenge",
    .callback = new_menu_select_callback
  };
  new_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Start Challenge",
    .callback = new_menu_select_callback
  };
  
  menu_sections[0] = (SimpleMenuSection)
		{
    .num_items = NUM_NEW_MENU_ITEMS,
    .items = new_menu_items,
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  new_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(new_menu_layer));
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void old_menu_select_callback(int index, void *ctx) 
{
  old_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(old_menu_layer));
}

void old_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	int num_a_items = 0;
  old_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Office Race",
    .callback = old_menu_select_callback
  };
  old_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "New Race",
    .callback = old_menu_select_callback
  };
  old_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Family",
    .callback = old_menu_select_callback
  };
	  old_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Friends",
    .callback = old_menu_select_callback
  };
  
  menu_sections[0] = (SimpleMenuSection)
		{
    .num_items = NUM_OLD_MENU_ITEMS,
    .items = old_menu_items,
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  old_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(old_menu_layer));
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void settings_menu_select_callback(int index, void *ctx) 
{
  settings_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(settings_menu_layer));
}

void settings_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	int num_a_items = 0;
  settings_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Vibration",
    .callback = settings_menu_select_callback
  };
  settings_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Invert Colors",
    .callback = settings_menu_select_callback
  };
  settings_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Units",
    .callback = settings_menu_select_callback
  };
  
  menu_sections[0] = (SimpleMenuSection)
		{
    .num_items = NUM_SETTINGS_MENU_ITEMS,
    .items = settings_menu_items,
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  settings_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(settings_menu_layer));
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void drawWindow(screen target, Window *window)
{
			switch(target)
			{
    case SPLASH: splash_window(window); return;
    case HOME: home_window(window); return;
    case ACTIVE:active_window(window); return;
				case NEW: new_window(window); return;
				case OLD: old_window(window); return;
				case SETTINGS: settings_window(window); return;
				case START: printf("pos inf"); return;
				case RACE: printf("pos inf"); return;
				case STATS: printf("pos inf"); return;
				case PAST_RACE: printf("pos inf"); return;
    default: printf("not special"); break;
   }	
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void window_load(Window *window)
{
	  //drawWindow(SPLASH, window);
   drawWindow(HOME, window);
	  //drawWindow(ACTIVE, window);
	  //drawWindow(NEW, window);
	  //drawWindow(OLD, window);
	  //drawWindow(SETTINGS, window);
	  
  
}
 
void window_unload(Window *window)
{
	 //Destroy GBitmaps
  gbitmap_destroy(tiny_bitmap);
  gbitmap_destroy(splash_bitmap);

  //Destroy BitmapLayers
  bitmap_layer_destroy(splash_layer);
	 simple_menu_layer_destroy(home_menu_layer);
	 simple_menu_layer_destroy(active_menu_layer);
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


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
 
int main(void)
{
  init();
  app_event_loop();
  deinit();
}

