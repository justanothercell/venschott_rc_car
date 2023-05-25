int selection = -1;

void configureBT(){
  textAlign(LEFT, BASELINE);
  ArrayList<String> names;
  background(255);
  textSize(40);
  strokeWeight(1);
  noStroke();
  fill(0);
  text(getBluetoothInformation(), 40, 80);
  
  text("Paired Devices:", 40, 320);
  names = bt.getPairedDeviceNames();
  for (int i=0; i < names.size(); i++)
  {
    if(mousePressed && mouseX > 40 && mouseX < width-80 && mouseY > 320 + 90 + i*60 && mouseY < 320 + 150 + i*60 ){
      selection = i;
    }
    fill(200);
    if(selection==i){
      fill(120);
    }
    rect(40, 320 + 90 + i*60, width-80, 60);
    fill(0);
    text("["+i+"] "+names.get(i).toString(), 60, 320 + 140 + i*60);
  }
  //text((mouseX > 40) +" "+ (mouseX < width-80) +" "+ (mouseY > offset + 90 + 60) +" "+ (mouseY < offset + 150 + 60), 40, height-80);
  //text("x:" + mouseX +" "+  offset + 90 + 60 +" < "+ mouseY  +" < "+  offset + 150 + 60, 40, height-20);
  
  if(selection >= 0 && selection < names.size()){
    textSize(100);
    fill(200);
    rect(100, height - 180, width - 200, 130);
    fill(0);
    text("Connect", 350, height-80);
    if(mouseX > 100 && mouseX < width - 200 && mouseY > height - 180 && mouseY < height - 50 && (selection >= 0 && selection < names.size())){
      for(String name:bt.getConnectedDeviceNames()){
        println("disconnected from:  " + name);
        bt.disconnectDevice(name);
      }
      bt.connectToDeviceByName(names.get(selection));
      println("connect to: " + names.get(selection));
      println("connected:");
      for(String name:bt.getConnectedDeviceNames()){
        println("  " + name);
      }
      println("end");
      isConfiguring = false;
      selectedElement = -1;
      selection = -1;
    }
  }
  else{
    text("Please pair a device and select it!", 60, height-80);
  }
  textAlign(CENTER, CENTER);
  textSize(u*72);
}

String getBluetoothInformation()
{
  String btInfo = "Server Running: ";
  btInfo += bt.isStarted() + "\n";
  btInfo += "Discovering: " + bt.isDiscovering() + "\n";
  btInfo += "Device Discoverable: "+bt.isDiscoverable() + "\n";
  return btInfo;
}

//required for BT enabling on startup
import android.content.Intent;
import android.os.Bundle;

import ketai.net.bluetooth.*;
import ketai.ui.*;
import ketai.net.*;

KetaiBluetooth bt;
String info = "";
KetaiList klist;

ArrayList<String> devicesDiscovered = new ArrayList();
boolean isConfiguring = true;

//********************************************************************
// The following code is required to enable bluetooth at startup.
//********************************************************************
void onCreate(Bundle savedInstanceState) {
  super.onCreate(savedInstanceState);
  bt = new KetaiBluetooth(this);
  println("Creating KetaiBluetooth");
}

void onActivityResult(int requestCode, int resultCode, Intent data) {
  bt.onActivityResult(requestCode, resultCode, data);
}

//********************************************************************

void onBluetoothDataEvent(String who, byte[] data)
{
  if (isConfiguring)
    return;

  println("recieved from '" + who + "': " + new String(data, StandardCharsets.UTF_8));
}

void sendData(int channel, int code){
  bt.broadcast((channel+";"+code+"\n").getBytes());
}
