De CSD repository kun je lokaal klonen.

```bash 
git clone git@github.com:ciskavriezenga/CSD_25-26.git 
```

Met bovenstaande 'installeer' je repo lokaal. 

Wanneer er nieuwe code online staat, hoef je enkel vanuit dat mapje in de terminal het volgende uit te voeren:
```bash 
git pull origin main
```


Vanaf blok 2b werken we met JUCE, deze kun je aan de lokale CSD repository toevoegen:
```bash
# navigeer in de terminal naar de map waar je de CSD repository hebt 'gecloned'
git submodule update --init
```
