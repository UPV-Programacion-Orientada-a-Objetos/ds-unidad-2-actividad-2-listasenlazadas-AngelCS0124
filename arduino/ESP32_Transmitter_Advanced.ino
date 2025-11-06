const char* mensajes[] = {
  // Mensaje 1: "HOLA MUNDO" con rotaciones
  "L,H", "L,O", "L,L", "M,3", "L,A", "L, ", "L,M", "L,U", "L,N", "L,D", "M,-3", "L,O",
  
  // Mensaje 2: "CIBERSEGURIDAD" 
  "M,1", "L,C", "L,I", "L,B", "L,E", "L,R", "M,2", "L,S", "L,E", "L,G", "L,U", "L,R", 
  "L,I", "L,D", "L,A", "L,D", "M,-3",
  
  // Mensaje 3: "PROTOCOLO PRT7"
  "L,P", "L,R", "L,O", "L,T", "L,O", "L,C", "L,O", "L,L", "L,O", "L, ", "L,P", "L,R", 
  "L,T", "L,7"
};

int mensajeActual = 0;
int indiceTrama = 0;

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("=== TRANSMISOR PRT-7 ESP32 ===");
  Serial.println("Iniciando secuencia de mensajes...");
  delay(1000);
}

void loop() {
  int numMensajes = 3; // Número de mensajes predefinidos
  int tramasPorMensaje[] = {12, 17, 14}; // Tramas por cada mensaje
  
  for (int msg = 0; msg < numMensajes; msg++) {
    Serial.println("--- INICIANDO MENSAJE ---");
    
    int inicio = 0;
    for (int i = 0; i < msg; i++) {
      inicio += tramasPorMensaje[i];
    }
    
    for (int i = 0; i < tramasPorMensaje[msg]; i++) {
      Serial.println(mensajes[inicio + i]);
      delay(800); // Delay reducido para testing
    }
    
    Serial.println("--- MENSAJE COMPLETADO ---");
    delay(3000); // Pausa entre mensajes
  }
  
  // No repetir automáticamente
  while(1) {
    delay(1000);
  }
}