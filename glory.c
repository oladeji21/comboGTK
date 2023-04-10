#include <gtk/gtk.h>
GtkWidget* window1;
GtkWidget* table1;
GtkWidget* hbox1;
GtkWidget* button1;
GtkWidget* label1;
GtkWidget* vbox1;
GtkWidget* entry1;
GtkWidget* entry2;
GtkWidget* button2;




void fn_layout_stuff( ){
window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
 
gtk_widget_set_size_request(window1, 500, 400 );
table1 = gtk_table_new(2, 2, FALSE); 
gtk_container_add(GTK_CONTAINER(window1), table1);
hbox1 = gtk_hbox_new(True, 1 ); 
gtk_table_attach( GTK_TABLE(table1), hbox1, 1, 2, 1, 2, GTK_EXPAND | GTK_SHRINK | GTK_FILL, GTK_EXPAND | GTK_SHRINK | GTK_FILL, 1, 2 );   
gtk_widget_set_size_request(hbox1, 150, 50 );
button1 = gtk_button_new_with_label("button");
gtk_box_pack_start( GTK_BOX(hbox1), button1, TRUE, TRUE, 0 ); 
gtk_widget_set_size_request(button1, 150, 50 );
label1 = gtk_label_new("label");
gtk_box_pack_start( GTK_BOX(hbox1), label1, TRUE, TRUE, 1 ); 
gtk_widget_set_size_request(label1, 150, 50 );
vbox1 = gtk_vbox_new(FALSE, 0 ); 
gtk_table_attach( GTK_TABLE(table1), vbox1, 1, 2, 0, 1, GTK_EXPAND, GTK_EXPAND, 0, 0 );   
gtk_widget_set_size_request(vbox1, 150, 50 );
entry1 = gtk_entry_new();
gtk_box_pack_start( GTK_BOX(vbox1), entry1, TRUE, TRUE, 0 ); 
gtk_widget_set_size_request(entry1, 150, 50 );
entry2 = gtk_entry_new();
gtk_box_pack_start( GTK_BOX(vbox1), entry2, TRUE, TRUE, 1 ); 
gtk_widget_set_size_request(entry2, 150, 50 );
button2 = gtk_button_new_with_label("button");
gtk_box_pack_start( GTK_BOX(vbox1), button2, TRUE, TRUE, 2 ); 
gtk_widget_set_size_request(button2, 150, 50 );



	g_signal_connect (
		button1,
		"clicked",
		goThere,
		NULL
	);
}
gboolean goThere(GtkWidget* w, gpointer data){

}