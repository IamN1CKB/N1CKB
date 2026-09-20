import paho.mqtt.client as mqtt
import ssl
import json

# Parametri della stampante
IP_STAMPANTE = "INSERISCI_IP"
PASSWORD = "INSERISCI_CODICE_ACCESSO"
SERIALE = "INSERISCI_NUMERO_SERIE"

topic_invio = f"device/{SERIALE}/request"

# Payload JSON per avviare un file precaricato sulla SD
payload = {
    "print": {
        "command": "project_file",
        "param": "file:///sdcard/nome_del_tuo_file.gcode.3mf",
        "url": "file:///sdcard/nome_del_tuo_file.gcode.3mf",
        "subtask_name": "nome_del_tuo_file",
        "use_ams": True, # Imposta a False se usi il portabobina esterno
        "ams_mapping": [0] # 0 indica il primo slot dell'AMS Lite
    }
}

def on_connect(client, userdata, flags, reason_code, properties):
    if reason_code == 0:
        print("Connesso al broker MQTT della stampante.")
        # Invia il payload formattato in JSON
        client.publish(topic_invio, json.dumps(payload))
        print("Comando di stampa inviato con successo.")
        client.disconnect()
    else:
        print(f"Errore di connessione: {reason_code}")

# Inizializza il client MQTT (sintassi per paho-mqtt v2)
client = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
client.username_pw_set("bblp", PASSWORD)

# Configurazione TLS per accettare il certificato autofirmato
client.tls_set(cert_reqs=ssl.CERT_NONE, tls_version=ssl.PROTOCOL_TLS_CLIENT)
client.tls_insecure_set(True)

client.on_connect = on_connect
client.connect(IP_STAMPANTE, 8883, 60)
client.loop_forever()