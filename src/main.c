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
	   PAST = 4,
	   SETTINGS = 5,
	   START = 6,
	   RACE = 7,
	   STATS = 8,
	   REVIEW = 9
} screen;
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];
	
	//Splash Elements
	static GBitmap *splash_bitmap;
	static BitmapLayer *splash_layer;
	
// Home Elements
#define NUM_HOME_MENU_ITEMS  4
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


// Past Elements
#define NUM_PAST_MENU_ITEMS  4
static SimpleMenuLayer* past_menu_layer;
static SimpleMenuItem past_menu_items[NUM_PAST_MENU_ITEMS];


// Settings Elements
#define NUM_SETTINGS_MENU_ITEMS  3
static SimpleMenuLayer* settings_menu_layer;
static SimpleMenuItem settings_menu_items[NUM_SETTINGS_MENU_ITEMS];


// Stats Elements
#define NUM_STATS_MENU_ITEMS  5
static SimpleMenuLayer* stats_menu_layer;
static SimpleMenuItem stats_menu_items[NUM_STATS_MENU_ITEMS];


// Review Elements
#define NUM_REVIEW_MENU_ITEMS  5
static SimpleMenuLayer* review_menu_layer;
static SimpleMenuItem review_menu_items[NUM_REVIEW_MENU_ITEMS];
static GBitmap *star_image;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


//void splash_select_callback(int index, void *ctx) 
//{
//  home_menu_items[index].subtitle = "You've hit select here!";
//  layer_mark_dirty(simple_menu_layer_get_layer(home_menu_layer));
//}

void splash_window(Window *window)
	{
	
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
 	
	 splash_bitmap= gbitmap_create_with_resource(RESOURCE_ID_SPLASH);
	 
	 splash_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
  bitmap_layer_set_bitmap(splash_layer, splash_bitmap);
	 //splash_layer.callback = splash_callback;
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
    .title = "Active Challenges",
    .callback = home_menu_select_callback
  };
  home_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "New Challenge",
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
			 .title = "Active Challenges",
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
			.title = "New Challenges",
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


void past_menu_select_callback(int index, void *ctx) 
{
  past_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(past_menu_layer));
}

void past_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	int num_a_items = 0;
  past_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Office Race",
    .callback = past_menu_select_callback
  };
  past_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "New Race",
    .callback = past_menu_select_callback
  };
  past_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Family",
    .callback = past_menu_select_callback
  };
	  past_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Friends",
    .callback = past_menu_select_callback
  };
  
  menu_sections[0] = (SimpleMenuSection)
		{
			.title = "Past Challenges",
    .num_items = NUM_PAST_MENU_ITEMS,
    .items = past_menu_items,
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  past_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(past_menu_layer));
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
			 .title = "Settings",
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


void stats_menu_select_callback(int index, void *ctx) 
{
  stats_menu_items[index].title = "End Run";
  layer_mark_dirty(simple_menu_layer_get_layer(stats_menu_layer));
}

void stats_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	int num_a_items = 0;
  stats_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Time Elapsed",
			.subtitle = "00:32:21"
		};
  stats_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Pace",
			.subtitle = "11:21 min/mi"
  };
  stats_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Distance",
			 .subtitle = "2.99 mi"
  };
	  stats_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Challenge",
				.subtitle = "By The New Year"
  };
		  stats_menu_items[num_a_items++] = (SimpleMenuItem)
				{
    .title = "Pause",
    .callback = stats_menu_select_callback
  };

  
  menu_sections[0] = (SimpleMenuSection)
		{
			.title = "Run Stats",
    .num_items = NUM_STATS_MENU_ITEMS,
    .items = stats_menu_items
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  stats_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(stats_menu_layer));
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void review_menu_select_callback(int index, void *ctx) 
{
  review_menu_items[index].subtitle = "You've hit select here!";
  layer_mark_dirty(simple_menu_layer_get_layer(review_menu_layer));
}

void review_window(Window *window)
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	 star_image = gbitmap_create_with_resource(RESOURCE_ID_VICTORY);
	int num_a_items = 0;
  review_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Challenge Type:",
			.subtitle = "Speed"
  };
  review_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Paid",
    .subtitle = "April 20, 2014"
  };
  review_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "1. Jeff Shaw",
    .subtitle = "Finished in 4h 02m. Won $60",
				.icon = star_image
  };
	  review_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "2. Megan Holtzblat",
    .subtitle = "Finished in 5h 08m. Won $0"
  };
		  review_menu_items[num_a_items++] = (SimpleMenuItem)
				{
    .title = "3. Angelo Caballo (You)",
    .subtitle = "Finished in 5h 45m. Won $0"
  };

  
  menu_sections[0] = (SimpleMenuSection)
		{
			.title = "Easter Marathon",
    .num_items = NUM_REVIEW_MENU_ITEMS,
    .items = review_menu_items,
  };
	
	 Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_frame(window_layer);

  // Initialize the simple menu layer
  review_menu_layer = simple_menu_layer_create(bounds, window, menu_sections, NUM_MENU_SECTIONS, NULL);

  // Add it to the window for display
  layer_add_child(window_layer, simple_menu_layer_get_layer(review_menu_layer));
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
				case PAST: past_window(window); return;
				case SETTINGS: settings_window(window); return;
				case START: printf("pos inf"); return;
				case RACE: printf("pos inf"); return;
				case STATS: stats_window(window); return;
				case REVIEW: review_window(window); return;
    default: printf("not special"); break;
   }	
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void window_load(Window *window)
{
	  //drawWindow(SPLASH, window);
   //drawWindow(HOME, window);
	  //drawWindow(ACTIVE, window);
	  //drawWindow(NEW, window);
	  //drawWindow(PAST, window);
	  //drawWindow(SETTINGS, window);
	  //drawWindow(STATS, window);
	  drawWindow(REVIEW, window);
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
	simple_menu_layer_destroy(new_menu_layer);
	simple_menu_layer_destroy(past_menu_layer);
	simple_menu_layer_destroy(settings_menu_layer);
	simple_menu_layer_destroy(stats_menu_layer);
	simple_menu_layer_destroy(review_menu_layer);
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

