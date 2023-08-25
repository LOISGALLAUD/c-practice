#include <stdio.h>
#include <curl/curl.h>

// Cette fonction sera utilisée pour écrire les données reçues dans le callback
size_t WriteCallback(void *contents, size_t size, size_t nmemb)
{
    size_t total_size = size * nmemb;
    printf("%.*s", (int)total_size, (char *)contents);
    return total_size;
}

int main()
{
    CURL *curl;
    CURLcode res;

    // Initialisation de libcurl
    curl_global_init(CURL_GLOBAL_DEFAULT);

    // Initialisation de la session CURL
    curl = curl_easy_init();
    if (curl)
    {
        // URL à scraper
        const char *url = "https://bandcamp.com/tag/ambient";

        // Configuration de l'URL et de la fonction de callback pour les données reçues
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Exécution de la requête
        res = curl_easy_perform(curl);

        // Vérification des erreurs
        if (res != CURLE_OK)
        {
            fprintf(stderr, "Erreur lors de la requête : %s\n", curl_easy_strerror(res));
        }

        // Fermeture de la session CURL
        curl_easy_cleanup(curl);
    }

    // Libération des ressources libcurl
    curl_global_cleanup();

    return 0;
}
