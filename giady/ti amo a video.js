function pausa(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}


let frase = "Giada, non ti permettere di mandare questo sito agli altri"; //"Ti amo Giada";
let fraseStamp = "";
async function ciclo() {
    for (let i = 0; i < frase.length; i++) {
        let char = 32;
        while (String.fromCharCode(char) != frase[i]) {
                char++;
                console.log(fraseStamp + String.fromCharCode(char));
                await pausa(5);
            }
            
            await pausa(50);
            fraseStamp = fraseStamp + String.fromCharCode(char);
        }
}

ciclo();