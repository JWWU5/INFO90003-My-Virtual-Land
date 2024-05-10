using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System.Threading;
public class SerialCommunication : MonoBehaviour {
    public SerialPort data_stream;

    public GameObject cube;

    void Start() //Awake() is called before Start()
    {
        //Open the serial stream
        data_stream = new SerialPort("/dev/cu.usbserial-574A0023111", 9600);
        data_stream.Open();
        data_stream.WriteLine("1");
    }

    // Update is called once per frame

    IEnumerator Incoming()
    {
        string message = data_stream.ReadLine(); // Read a line of data
        Debug.Log("Message from Arduino: " + message);
        if (message.Trim() == "white") {
            GenerateRandomCube();
        }
        
        yield return null;
    }
    void Update()
    {
        StartCoroutine(Incoming());
        
    }

    public void GenerateRandomCube()
    {
        // Generate a random position within a defined range
        Vector3 randomPosition = new Vector3(Random.Range(-5f, 5f), Random.Range(-5f, 5f), Random.Range(-5f, 5f));
        
        // Instantiate the cube at the random position
        Instantiate(cube, randomPosition, Quaternion.identity);
    }
}