#define TAILLE 100
#define OK 0
#define ERREUR_VIDE 1
#define ERREUR_PLEINE 2
/*
 * @brief cree/initialise une file vide sous forme d'un tableau.
 */
void creer_file(char *itab[], unsigned int itete, unsigned int iqueue, unsigned int nb_elem);
/*
 * @brief affiche la file t contenant nb_elem, a partir de la tete itete.
 */
void afficher_file(char t[], int itete, int nb_elem);
/*
 * @brief enfile l'element nv_val dans la file t, a partir de la queue iqueue.
 */
int enfiler(char nv_val, char t[], int *iqueue, int *nb_elem);
/*
 * @brief enleve l'element tete_val de la file t, a partir de la tete itete.
 */
int defiler(char t[], int *itete, int *nb_elem, char *tete_val);
