/* xep136_plugin.h */

typedef struct {
    GtkWidget *show_table;

    GtkWidget *label_enable;
    GtkWidget *label_disable;
    GtkWidget *label_status;
    GtkWidget *enable;
    GtkWidget *disable;
    GtkWidget *status;

    GtkWidget *label_from;
    GtkWidget *from_day;
    GtkWidget *from_month;
    GtkWidget *from_year;

    GtkWidget *label_to;
    GtkWidget *to_day;
    GtkWidget *to_month;
    GtkWidget *to_year;

    GtkWidget *show_button;
} RightStruct;

typedef struct _WindowStruct {
    GtkWidget *window;

    GtkWidget *mainbox;
    GtkWidget *left;
    GtkWidget *center;
    GtkWidget *rightbox;

    //center
    GtkWidget *label_username;
    GtkWidget *imhtml;
    GtkWidget *imhtml_win;
    
    //right
    RightStruct *showtable_struct;

    //left
    GtkTreeStore *treestore;
    GtkWidget *treeview;

    //conversation
    PidginConversation *gtkconv;

    //xmlns for current server
    char *xmlns;

    //id for xmlns
    char *id;

    // retrieved collections
    GList *coll;

} WindowStruct;

typedef struct {
    gchar *start;
    gchar *with;
} RetrieveCollection;

typedef struct {
    PidginConversation *gtkconv;
    gboolean included;
} Test_struct;

typedef struct {
//    PurpleConnection *gc;
    xmlnode *xml;
    char *id;
    gboolean match;
} Recipient_info;

/* misc functions, increase_start_time, get_server_name, find_recipient */
static gchar * increase_start_time(gchar *start);
static gchar * get_server_name(PidginConversation *gtkconv);
static void find_recipient(WindowStruct *curr, Recipient_info *recipient);

/* explore received xmlnode, manage collections */

static void send_propher_name(RetrieveCollection *coll, RetrieveCollection *new);
static void retrieve_collection(WindowStruct *curr, char *start);
static void iq_retrieve_body(WindowStruct *curr, xmlnode *c, xmlnode *d);
static void iq_retrieve(WindowStruct *curr, xmlnode *xml);
static void empty_collection(WindowStruct *curr);
static void add_collection(WindowStruct *curr, gchar *start, gchar *with);
static void iq_list(WindowStruct *curr, xmlnode *xml);
static void iq_pref(WindowStruct *curr, xmlnode *xml);
static void iq_query_supported(WindowStruct *curr);
static void iq_query(WindowStruct *curr, xmlnode *xml);
static void explore_xml(WindowStruct *curr, xmlnode *xml);
static void xmlnode_received(PurpleConnection *gc, xmlnode **packet, gpointer null);

/* send message, service discovery, show, enable, disable, status */
static void message_send(char *message, PidginConversation *gtkconv);
static void send_iq_list(WindowStruct *curr, gchar *from, gchar *to);
static void send_pref_info(WindowStruct *curr);
static void status_clicked(GtkWidget *button, WindowStruct *curr);
static void disable_clicked(GtkWidget *button, WindowStruct *curr);
static void enable_clicked(GtkWidget *button, WindowStruct *curr);
static void show_clicked(GtkWidget *button, WindowStruct *curr);
static void send_disco_info(WindowStruct *curr);

/* GTK create, destroy, history window */
static void history_window_destroy(GtkWidget *window, WindowStruct *curr);
static void date_selected(GtkTreeSelection *sel, WindowStruct *curr);
static void create_right_table(WindowStruct *history_window);
static void create_left_list(WindowStruct *history_window);
static void history_window_create(WindowStruct *history_window);
static void history_window_open(PidginConversation *gtkconv);
static void history_window_exist_test(WindowStruct *curr, Test_struct *test);
static void history_button_clicked(GtkWidget *button, PidginConversation *gtkconv);

/* attach, detach, history_button */
static gboolean if_jabber(PidginConversation *gtkconv);
static void destroy_windows(WindowStruct *curr);
static void destroy_history_window(WindowStruct *curr, PidginConversation *gtkconv);
static void conv_deleted(PurpleConversation *conv, gpointer null);
static void detach_from_gtkconv(PidginConversation *gtkconv, gpointer null);
static void attach_to_gtkconv(PidginConversation *gtkconv, gpointer null);
static void detach_from_pidgin_window(PidginWindow *win, gpointer null);
static void attach_to_pidgin_window(PidginWindow *win, gpointer null);
static void detach_from_all_windows();
static void attach_to_all_windows();
static void conv_created(PurpleConversation *conv, gpointer null);
