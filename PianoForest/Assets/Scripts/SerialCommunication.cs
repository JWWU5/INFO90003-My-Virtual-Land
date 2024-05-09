using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System.Threading;
public class SerialCommunication : MonoBehaviour {
    public SerialPort data_stream = new SerialPort("/dev/cu.usbserial-574A0023111", 9600);


    void Start() //Awake() is called before Start()
    {
   
        //Open the serial stream
        data_stream.Open();
        data_stream.WriteLine("1");

        
  
    }

    // Update is called once per frame

    IEnumerator Incoming()
    {
        string message = data_stream.ReadLine(); // Read a line of data
        Debug.Log("Message from Arduino: " + message);

        yield return null;
    }
    void Update()
    {
        StartCoroutine(Incoming());
    }
}