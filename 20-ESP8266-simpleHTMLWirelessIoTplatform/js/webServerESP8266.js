function searchDevices(){

}

function connectToDevice(){

}

function disconnectToDevice(){

}

function createNewFile(){

}

function startAccquisition(){

}

function stopAccquisition(){

}


function scanNetworks() {
    if(this.isDeviceConnected == false)
    {
      this.$bvModal.show('modal-running-task');
      this.isTaskRunning = false;
      this.taskStatus = "Device not connected";
      return;
    }
    console.log("scanNetworks");
    this.ssidList = "";     
    this.isScanning = true;
    this.socket.send('scanNetworks');
}