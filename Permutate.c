#include <gtk/gtk.h>

#include "Permutate.h"
#include "Controller-Perm-Share.h"

int main(int argc, char* argv[])
{





	gtk_init(&argc, &argv);




	Mainwindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_widget_set_size_request(Mainwindow, 400, 490 );

	layout1 = gtk_layout_new(NULL,NULL); 
	gtk_container_add(GTK_CONTAINER(Mainwindow), layout1);

	PaternEntry = gtk_entry_new();
	gtk_layout_put (GTK_LAYOUT (layout1), PaternEntry,20, 50 ); 
	gtk_widget_set_size_request(PaternEntry, 350, 50 );

	AvailSpacesBox = gtk_entry_new();
	gtk_layout_put (GTK_LAYOUT (layout1), AvailSpacesBox,20, 120 ); 
	gtk_widget_set_size_request(AvailSpacesBox, 100, 50 );

	label1 = gtk_label_new("R");
	gtk_layout_put (GTK_LAYOUT (layout1), label1,125, 120 ); 
	gtk_widget_set_size_request(label1, 50, 50 );

	PermutateCheck = gtk_check_button_new_with_label ("Permutate");
	gtk_layout_put (GTK_LAYOUT (layout1), PermutateCheck,184, 120 ); 
	gtk_widget_set_size_request(PermutateCheck, 100, 50 );
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (PermutateCheck), TRUE);

	ResultBox = gtk_text_view_new ();
	gtk_layout_put (GTK_LAYOUT (layout1), ResultBox,20, 190 ); 
	gtk_widget_set_size_request(ResultBox, 350, 250 );

	ActionButton = gtk_button_new_with_label("Go");
	gtk_layout_put (GTK_LAYOUT (layout1), ActionButton,282, 120 ); 
	gtk_widget_set_size_request(ActionButton, 85, 50 );	


	gtk_signal_connect(
		GTK_OBJECT(Mainwindow),
		"delete_event",
		GTK_SIGNAL_FUNC(delete_event_cb),
		NULL
	);
	
	Collection = g_malloc(4*sizeof(GtkWidget*));

	Collection[0] = PaternEntry;
	Collection[1] = AvailSpacesBox;
	Collection[0] = PermutateCheck;
	Collection[0] = ResultBox;
	

	gtk_signal_connect(
		GTK_OBJECT(ActionButton),
		"clicked",
		GTK_SIGNAL_FUNC(button_click_cb),
		Collection
	);
/***/	
	gtk_widget_show_all(Mainwindow);
	gtk_main();
	
	return 0;
}

static gint delete_event_cb(GtkWidget* window, GdkEventAny* e, gpointer data)
{
	gtk_main_quit();
	return FALSE;
}

/*******/
