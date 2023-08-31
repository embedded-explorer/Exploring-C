#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "problems.h"

int main(){

//----------------------------------------------------------------------
// Problem 1.
//----------------------------------------------------------------------
    App_List *app_list;
    int i;
	
	// Applications
    Application new_app[30] = {{41, merit     , "Aruna"    },
                               {53, merit     , "Aryan"    },
                               {97, nri       , "Vikram"   },
                               {67, merit     , "Rahul"    },
                               {62, management, "Nisha"    },
                               {82, nri       , "Prateek"  },
                               {93, management, "Kavya"    },
                               {54, nri       , "Riya"     },
                               {34, merit     , "Meera"    },
                               {11, merit     , "Pooja"    },
                               {62, merit     , "Ishita"   },
                               {29, merit     , "Rohit"    },
                               {16, merit     , "Sanya"    },
                               {96, nri       , "Aditya"   },
                               {61, management, "Abhinav"  },
                               {95, management, "Varun"    },
                               {25, merit     , "Yash"     },
                               {62, merit     , "Karan"    },
                               {75, nri       , "Ananya"   },
                               {90, nri       , "Swati"    },
                               {18, merit     , "Nikhil"   },
                               {51, merit     , "Tanvi"    },
                               {41, management, "Priya"    },
                               {54, nri       , "Alisha"   },
                               {94, management, "Sneha"    },
                               {7 , merit     , "Aniket"   },
                               {96, merit     , "Rajat"    },
                               {5 , merit     , "Arjun"    },
                               {17, merit     , "Akshay"   },
	                           {95, management, "Neha"     }};

	// Test initialization function
    app_list = initialise_array(30);
    assert(app_list->c_size == 0 && app_list->t_size == 30);

    // Test apply for course
	for(i=0; i<30; i++){
      assert(apply_for_course(app_list, new_app[i]));
	}
	assert(app_list->c_size == 30);
	
	// Test allocate seats function
	allocate_seats(app_list);
	
	// Test Display application list
	display_app_list(app_list);

    return 0;
}