#include <stdio.h>
#include <gtk/gtk.h>

//Declaração de variáveis globais
GtkWidget *janela;
GtkWidget *botao;
GtkWidget *box;
GtkWidget *texto;

//Função para mudar o texto da label principal
void mudaTexto(){
	gtk_label_set_text(GTK_LABEL(texto), "Olá mundo!");
}

//Função que cria a janela
void activate(GtkApplication *app, gpointer user_data){
	janela = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(janela), "Hell World!");
	gtk_window_set_default_size(GTK_WINDOW(janela), 1200, 720);
	
	box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	gtk_widget_set_halign (box, GTK_ALIGN_CENTER);
	gtk_widget_set_valign (box, GTK_ALIGN_CENTER);

	botao = gtk_button_new_with_label("Click");
	g_signal_connect(botao, "clicked", G_CALLBACK(mudaTexto), NULL);

	texto = gtk_label_new(NULL);
	
	gtk_container_add(GTK_CONTAINER(box), botao);
	gtk_container_add(GTK_CONTAINER(box), texto);
	gtk_container_add(GTK_CONTAINER(janela), box);

	gtk_widget_show_all(janela);
}

//Função principal
int main(int    argc, char **argv){
	GtkApplication *app;
	int status;

	app = gtk_application_new("testgui.desktop", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);
	return status;
}
