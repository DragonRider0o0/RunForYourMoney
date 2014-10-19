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
	   REVIEW = 9,
	   PEBBLE = 10
} screen;

static screen origin_screen;
static screen target_screen;
	static int ticks;
static SimpleMenuSection menu_sections[NUM_MENU_SECTIONS];

void click_config_provider(void *context);
void select_config_provider(void *context);
void back_config_provider(void *context);
void drawScreen(screen target_screen);
void flag_handler(struct tm *tick_time, TimeUnits units_changed);
void run_handler(struct tm *tick_time, TimeUnits units_changed);
	
	//Splash Elements
	static GBitmap *splash_bitmap;
	static BitmapLayer *splash_layer;
	
// Home Elements
#define NUM_HOME_MENU_ITEMS  5
static SimpleMenuLayer* home_menu_layer;
static SimpleMenuItem home_menu_items[NUM_HOME_MENU_ITEMS];



// Active Elements
#define NUM_ACTIVE_MENU_ITEMS  5
static SimpleMenuLayer* active_menu_layer;
static SimpleMenuItem active_menu_items[NUM_ACTIVE_MENU_ITEMS];


// New Elements
#define NUM_NEW_MENU_ITEMS  3
static SimpleMenuLayer* new_menu_layer;
static SimpleMenuItem new_menu_items[NUM_NEW_MENU_ITEMS];


// Past Elements
#define NUM_PAST_MENU_ITEMS  5
static SimpleMenuLayer* past_menu_layer;
static SimpleMenuItem past_menu_items[NUM_PAST_MENU_ITEMS];


// Settings Elements
#define NUM_SETTINGS_MENU_ITEMS  4
static SimpleMenuLayer* settings_menu_layer;
static SimpleMenuItem settings_menu_items[NUM_SETTINGS_MENU_ITEMS];


// Start Elements
	static GBitmap *flag_1_bitmap;
	static BitmapLayer *flag_1_layer;
	static GBitmap *flag_2_bitmap;
	static BitmapLayer *flag_2_layer;
	static GBitmap *flag_3_bitmap;
	static BitmapLayer *flag_3_layer;
	static GBitmap *flag_4_bitmap;
	static BitmapLayer *flag_4_layer;
	static GBitmap *flag_4_bitmap;
	static BitmapLayer *flag_4_layer;
	static GBitmap *flag_5_bitmap;
	static BitmapLayer *flag_5_layer;
	static GBitmap *flag_6_bitmap;
	static BitmapLayer *flag_6_layer;
	static GBitmap *flag_7_bitmap;
	static BitmapLayer *flag_7_layer;


// Race Elements
	static GBitmap *run_1_bitmap;
	static BitmapLayer *run_1_layer;
	static GBitmap *run_2_bitmap;
	static BitmapLayer *run_2_layer;
	static GBitmap *run_3_bitmap;
	static BitmapLayer *run_3_layer;
	static GBitmap *run_4_bitmap;
	static BitmapLayer *run_4_layer;
	static GBitmap *run_4_bitmap;
	static BitmapLayer *run_4_layer;
	static GBitmap *run_5_bitmap;
	static BitmapLayer *run_5_layer;
	static GBitmap *run_6_bitmap;
	static BitmapLayer *run_6_layer;


// Stats Elements
#define NUM_STATS_MENU_ITEMS  6
static SimpleMenuLayer* stats_menu_layer;
static SimpleMenuItem stats_menu_items[NUM_STATS_MENU_ITEMS];


// Review Elements
#define NUM_REVIEW_MENU_ITEMS  6
static SimpleMenuLayer* review_menu_layer;
static SimpleMenuItem review_menu_items[NUM_REVIEW_MENU_ITEMS];
static GBitmap *star_image;

////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void splash_window()
	{
	 origin_screen = PEBBLE;
	 target_screen =  HOME;
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
 	switch(index)
		{
				case 0: target_screen = ACTIVE; origin_screen = HOME; break;
			 case 1: target_screen = NEW; origin_screen = HOME; break;
			 case 2: target_screen = PAST; origin_screen = HOME; break;
			 case 3: target_screen = SETTINGS; origin_screen = HOME; break;
			 case 4: target_screen = SPLASH; origin_screen = HOME; break;
			 default: break;
		};
  drawScreen(target_screen);
}

void home_window()
{
	 origin_screen = SPLASH;
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
			  home_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Back",
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
   	switch(index)
		{
				case 0: target_screen = START; 	origin_screen = ACTIVE; break;
			 case 1: target_screen = START; 	origin_screen = ACTIVE; break;
			 case 2: target_screen = START; 	origin_screen = ACTIVE; break;
			 case 3: target_screen = START; 	origin_screen = ACTIVE; break;
					case 4: target_screen = SPLASH; origin_screen = ACTIVE; break;
			 default: break;
		};
  drawScreen(target_screen);
}

void active_window()
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
		  active_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Back",
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
  switch(index)
		{
				case 0: target_screen = START;	origin_screen = NEW; break;
			 case 1: target_screen = START; origin_screen = NEW; break;
			case 2: target_screen = SPLASH; origin_screen = NEW; break;
			 default: break;
		};
  drawScreen(target_screen);
}

void new_window()
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
			  new_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Back",
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
  switch(index)
		{
				case 0: target_screen = REVIEW; origin_screen = PAST; break;
			 case 1: target_screen = REVIEW; origin_screen = PAST; break;
			 case 2: target_screen = REVIEW; origin_screen = PAST; break;
			 case 3: target_screen = REVIEW; origin_screen = PAST; break;
			 case 4: target_screen = SPLASH; origin_screen = PAST; break;
			 default: break;
		};
  drawScreen(target_screen);
}

void past_window()
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
			  past_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Back",
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
  switch(index)
		{
				case 0: target_screen = SETTINGS; vibes_long_pulse(); break;
			 case 1: target_screen = SETTINGS; break;
			 case 2: target_screen = SETTINGS; break;
		 	case 3: target_screen = SPLASH; origin_screen = SETTINGS; break;
			 default: break;
		};
  drawScreen(target_screen);
}

void settings_window()
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
			  settings_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Back",
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

void start_window()
	{
	ticks = 0;
	 target_screen =  RACE;
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	flag_1_bitmap= gbitmap_create_with_resource(RESOURCE_ID_FLAG_1);
	flag_2_bitmap= gbitmap_create_with_resource(RESOURCE_ID_FLAG_2);
	flag_3_bitmap= gbitmap_create_with_resource(RESOURCE_ID_FLAG_3);
	flag_4_bitmap= gbitmap_create_with_resource(RESOURCE_ID_FLAG_4);
	flag_5_bitmap= gbitmap_create_with_resource(RESOURCE_ID_FLAG_5);
	flag_6_bitmap= gbitmap_create_with_resource(RESOURCE_ID_FLAG_6);
	flag_7_bitmap= gbitmap_create_with_resource(RESOURCE_ID_FLAG_7);

	 
	flag_1_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	flag_2_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	flag_3_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	flag_4_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	flag_5_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	flag_6_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	flag_7_layer = bitmap_layer_create(GRect(0, 0, 144, 168));
	
  bitmap_layer_set_bitmap(flag_1_layer, flag_1_bitmap);
	bitmap_layer_set_bitmap(flag_2_layer, flag_2_bitmap);
	bitmap_layer_set_bitmap(flag_3_layer, flag_3_bitmap);
	bitmap_layer_set_bitmap(flag_4_layer, flag_4_bitmap);
	bitmap_layer_set_bitmap(flag_5_layer, flag_5_bitmap);
	bitmap_layer_set_bitmap(flag_6_layer, flag_6_bitmap);
	bitmap_layer_set_bitmap(flag_7_layer, flag_7_bitmap);
	 //splash_layer.callback = splash_callback;
  tick_timer_service_subscribe(SECOND_UNIT, (TickHandler) flag_handler);
	
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void race_window()
	{
	ticks = 0;
	 target_screen =  STATS;
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	run_1_bitmap= gbitmap_create_with_resource(RESOURCE_ID_RUN_1);
	run_2_bitmap= gbitmap_create_with_resource(RESOURCE_ID_RUN_2);
	run_3_bitmap= gbitmap_create_with_resource(RESOURCE_ID_RUN_3);
	run_4_bitmap= gbitmap_create_with_resource(RESOURCE_ID_RUN_4);
	run_5_bitmap= gbitmap_create_with_resource(RESOURCE_ID_RUN_5);
	run_6_bitmap= gbitmap_create_with_resource(RESOURCE_ID_RUN_6);
	 
	run_1_layer = bitmap_layer_create(GRect(20, 80, 40, 40));
	run_2_layer = bitmap_layer_create(GRect(20, 80, 40, 40));
	run_3_layer = bitmap_layer_create(GRect(20, 80, 40, 40));
	run_4_layer = bitmap_layer_create(GRect(20, 80, 40, 40));
	run_5_layer = bitmap_layer_create(GRect(20, 80, 40, 40));
	run_6_layer = bitmap_layer_create(GRect(20, 80, 40, 40));

	
  bitmap_layer_set_bitmap(run_1_layer, run_1_bitmap);
	bitmap_layer_set_bitmap(run_2_layer, run_2_bitmap);
	bitmap_layer_set_bitmap(run_3_layer, run_3_bitmap);
	bitmap_layer_set_bitmap(run_4_layer, run_4_bitmap);
	bitmap_layer_set_bitmap(run_5_layer, run_5_bitmap);
	bitmap_layer_set_bitmap(run_6_layer, run_6_bitmap);

	 //splash_layer.callback = splash_callback;
  tick_timer_service_subscribe(SECOND_UNIT, (TickHandler) run_handler);
	
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void stats_menu_select_callback(int index, void *ctx) 
{
	  switch(index)
		{
				case 0: target_screen = STATS; break;
			 case 1: target_screen = STATS; break;
			 case 2: target_screen = STATS; break;
				case 3: target_screen = STATS; break;
				case 4: 
				{
					if(strcmp(stats_menu_items[index].title,"Pause"))
					{
						stats_menu_items[index].title = "End Run"; 
						layer_mark_dirty(simple_menu_layer_get_layer(stats_menu_layer));
					} 
					else
					{
						target_screen = SPLASH; 
					} return;
				}
				case 5: target_screen = SPLASH; origin_screen = STATS; 
					break;
			 default: break;
		};
  drawScreen(target_screen);
}

void stats_window()
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
			  stats_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Back",
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
  switch(index)
		{
				case 0: target_screen = REVIEW; break;
			 case 1: target_screen = REVIEW; break;
			 case 2: target_screen = REVIEW; break;
		 	case 3: target_screen = REVIEW; break;
			 case 4: target_screen = REVIEW; break;
			 case 5: target_screen = SPLASH; origin_screen = REVIEW; break;
			 default: break;
		};
  drawScreen(target_screen);
}

void review_window()
{
	 tiny_bitmap = gbitmap_create_with_resource(RESOURCE_ID_TINY);
 	window_set_status_bar_icon	(window, tiny_bitmap);
	
	 star_image = gbitmap_create_with_resource(RESOURCE_ID_STAR_BADGE);
	int num_a_items = 0;
  review_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Challenge Type:",
			.subtitle = "Speed"
  };
  review_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "Bounty: $60",
    .subtitle = "April 20, 2014"
  };
  review_menu_items[num_a_items++] = (SimpleMenuItem)
		{
    .title = "1. Jeff Shaw",
    .subtitle = "Time: 4h 02m",
				.icon = star_image
  };
	  review_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "2. Megan Holtzblat",
    .subtitle = "Time: 5h 08m"
  };
		  review_menu_items[num_a_items++] = (SimpleMenuItem)
				{
    .title = "3. Angelo Caballo",
    .subtitle = "Time: 5h 45m"
  };
			  review_menu_items[num_a_items++] = (SimpleMenuItem)
			{
    .title = "Back",
    .callback = review_menu_select_callback
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


void window_load()
{
	  //drawWindow(SPLASH, window);
	  //drawWindow(SPLASH, window);
   //drawWindow(HOME, window);
	  //drawWindow(ACTIVE, window);
	  //drawWindow(NEW, window);
	  //drawWindow(PAST, window);
	  //drawWindow(SETTINGS, window);
	  //drawWindow(STATS, window);
	  //drawWindow(REVIEW, window);
}
 
void window_unload(Window *window)
{
	 //Destroy GBitmaps
  gbitmap_destroy(tiny_bitmap);
  gbitmap_destroy(splash_bitmap);

  //Destroy BitmapLayers
  bitmap_layer_destroy(splash_layer);
	bitmap_layer_destroy(flag_1_layer);
	bitmap_layer_destroy(flag_2_layer);
	bitmap_layer_destroy(flag_3_layer);
	bitmap_layer_destroy(flag_4_layer);
	bitmap_layer_destroy(flag_5_layer);
	bitmap_layer_destroy(flag_6_layer);
	bitmap_layer_destroy(flag_7_layer);
		bitmap_layer_destroy(run_1_layer);
	bitmap_layer_destroy(run_2_layer);
	bitmap_layer_destroy(run_3_layer);
	bitmap_layer_destroy(run_4_layer);
	bitmap_layer_destroy(run_5_layer);
	bitmap_layer_destroy(run_6_layer);
	
	 simple_menu_layer_destroy(home_menu_layer);
	 simple_menu_layer_destroy(active_menu_layer);
	simple_menu_layer_destroy(new_menu_layer);
	simple_menu_layer_destroy(past_menu_layer);
	simple_menu_layer_destroy(settings_menu_layer);
	simple_menu_layer_destroy(stats_menu_layer);
	simple_menu_layer_destroy(review_menu_layer);
}

void reset_window()
	{
		 //Destroy GBitmaps
  gbitmap_destroy(tiny_bitmap);
	tiny_bitmap = NULL;
  gbitmap_destroy(splash_bitmap);
	splash_bitmap = NULL;

  //Destroy BitmapLayers
  bitmap_layer_destroy(splash_layer);
	splash_layer = NULL;
		bitmap_layer_destroy(flag_1_layer);
	flag_1_layer = NULL;
	bitmap_layer_destroy(flag_2_layer);
	flag_2_layer = NULL;
	bitmap_layer_destroy(flag_3_layer);
	flag_3_layer = NULL;
	bitmap_layer_destroy(flag_4_layer);
	flag_4_layer = NULL;
	bitmap_layer_destroy(flag_5_layer);
	flag_5_layer = NULL;
	bitmap_layer_destroy(flag_6_layer);
	flag_6_layer = NULL;
	bitmap_layer_destroy(flag_7_layer);
	flag_7_layer = NULL;
		run_1_layer = NULL;
	bitmap_layer_destroy(run_2_layer);
	run_2_layer = NULL;
	bitmap_layer_destroy(run_3_layer);
	run_3_layer = NULL;
	bitmap_layer_destroy(run_4_layer);
	run_4_layer = NULL;
	bitmap_layer_destroy(run_5_layer);
	run_5_layer = NULL;
	bitmap_layer_destroy(run_6_layer);
	run_6_layer = NULL;
	
	 simple_menu_layer_destroy(home_menu_layer);
	home_menu_layer = NULL;
	 simple_menu_layer_destroy(active_menu_layer);
	active_menu_layer = NULL;
  simple_menu_layer_destroy(new_menu_layer);
	new_menu_layer = NULL;
	 simple_menu_layer_destroy(past_menu_layer);
	past_menu_layer = NULL;
	 simple_menu_layer_destroy(settings_menu_layer);
	settings_menu_layer = NULL;
	 simple_menu_layer_destroy(stats_menu_layer);
	stats_menu_layer = NULL;
	 simple_menu_layer_destroy(review_menu_layer);
	review_menu_layer = NULL;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void drawScreen(screen target)
{
	  reset_window();
			switch(target)
			{
    case SPLASH: splash_window(); break;
    case HOME: home_window(); break;
    case ACTIVE:active_window(); break;
				case NEW: new_window(); break;
				case PAST: past_window(); break;
				case SETTINGS: settings_window(); break;
				case START: start_window(); break;
				case RACE: race_window(); break;
				case STATS: stats_window(); break;
				case REVIEW: review_window(); break;
				case PEBBLE:  window_stack_pop(true);
    default: printf("not special"); break;
   }
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

 
void select_click_handler(ClickRecognizerRef recognizer, void *context)
{
	vibes_short_pulse();
	drawScreen(target_screen);
}

void back_click_handler(ClickRecognizerRef recognizer, void *context)
{
	//vibes_long_pulse();
	vibes_short_pulse();
	drawScreen(origin_screen);
}


void click_config_provider(void *context)
{
		 	window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
	   window_single_click_subscribe(BUTTON_ID_BACK, back_click_handler);
}

void select_config_provider(void *context)
{
		 	window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
}

void back_config_provider(void *context)
{
	   window_single_click_subscribe(BUTTON_ID_BACK, back_click_handler);
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////


void flag_handler(struct tm *tick_time, TimeUnits units_changed)
{
				switch(ticks)
					{
						case 0:  layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(flag_1_layer)); vibes_short_pulse();	break;
					 case 1:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(flag_2_layer));	break;
					 case 2:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(flag_3_layer));	break;
					 case 3:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(flag_4_layer)); vibes_short_pulse();	break;
					 case 4:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(flag_5_layer));	break;
					 case 5:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(flag_6_layer));	break;
					 case 6:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(flag_7_layer)); vibes_long_pulse();	break;
      default: layer_remove_child_layers(window_get_root_layer(window)); tick_timer_service_unsubscribe(); origin_screen = START;  drawScreen(RACE);	 break;
				}
	ticks = ticks + 1;
}


void run_handler(struct tm *tick_time, TimeUnits units_changed)
{
				switch(ticks)
					{
						case 0:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(run_1_layer));	break;
					 case 1:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(run_2_layer));	break;
					 case 2:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(run_3_layer));	break;
					 case 3:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(run_4_layer)); break;
					 case 4:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(run_5_layer));	break;
					 case 5:  layer_remove_child_layers(window_get_root_layer(window)); layer_add_child(window_get_root_layer(window), bitmap_layer_get_layer(run_6_layer));	break;
      default: ticks = 0; return;
				}
	ticks = ticks + 1;
}


////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
 
void init()
{
  //Initialize the app elements here!
  window = window_create();
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
	
	drawScreen(SPLASH);
	window_set_click_config_provider(window, click_config_provider);
	
	window_stack_push(window, true);
	
	//tick_timer_service_subscribe(SECOND_UNIT, (TickHandler) tick_handler);
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

