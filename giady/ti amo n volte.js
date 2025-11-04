// Configurazione: numero di messaggi e testo da inviare
//apri la chat, scrivi il messaggio da inviare (non pensare alla variabile "messaggio") ed esegui il programma
const numeroMessaggi = 200; // Numero di volte che vuoi inviare il messaggio
const messaggio = "Ti amo"; // Il messaggio da inviare

// Funzione per inviare il messaggio
function inviaMessaggi() {
    // Trova il campo di input del messaggio
    const inputBox = document.querySelector("[contenteditable='true'][data-tab='10']");
    if (!inputBox) {
        console.error("Non riesco a trovare il campo di input della chat.");
        return;
    }

    for (let i = 0; i < numeroMessaggi; i++) {
        // Simula l'inserimento del messaggio
        inputBox.textContent = messaggio;

        // Simula l'evento di input per rendere il messaggio visibile
        const inputEvent = new InputEvent("input", { bubbles: true });
        inputBox.dispatchEvent(inputEvent);

        // Trova e clicca il pulsante "Invia"
        const sendButton = document.querySelector("button[data-tab='11'][aria-label='Invia'][class='x1c4vz4f x2lah0s xdl72j9 xfect85 x1iy03kw x1lfpgzf']");
        if (sendButton) {
            sendButton.click();
        } else {
            console.error("Non riesco a trovare il pulsante di invio.");
            return;
        }
    }

    console.log(`Messaggi inviati con successo: ${numeroMessaggi}`);
}

// Esegui la funzione
inviaMessaggi();