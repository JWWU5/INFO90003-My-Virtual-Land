using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System.Threading;
using UnityEngine.SceneManagement;
public class SerialCommunication : MonoBehaviour {
    public SerialPort data_stream;

    // white key: generate different types of tree
    public GameObject tree_one;
    public GameObject tree_two;
    public GameObject tree_three;
    public GameObject tree_four;
    public GameObject tree_five;
    public GameObject tree_six;
    public GameObject tree_seven;
    // black key: play music
    public GameObject audio_one;
    public GameObject audio_two;
    public GameObject rain_mode;
    public GameObject audio_four;
    public GameObject audio_five;

    // huge red button
    public GameObject dayLight;

    void Awake() {
        //black_three.SetActive(false);
    }

    void Start() //Awake() is called before Start()
    {
        //Open the serial stream
        data_stream = new SerialPort("/dev/cu.usbserial-574A0023111", 9600);
        data_stream.Open();
        data_stream.WriteLine("1");
        StartCoroutine(Incoming());
    }

    // Update is called once per frame
    IEnumerator Incoming()
    {
        while(true) {
            string message = data_stream.ReadLine(); // Read a line of data
            Debug.Log("Message from Arduino: " + message);

            switch (message.Trim()) {
                // white keys function
                case "white_1":
                    TreeGeneration(tree_one);
                    break;
                case "white_2":
                    TreeGeneration(tree_two);
                    break;
                case "white_3":
                    TreeGeneration(tree_three);
                    break;
                case "white_4":
                    TreeGeneration(tree_four);
                    break;
                case "white_5":
                    TreeGeneration(tree_five);
                    break;
                case "white_6":
                    TreeGeneration(tree_six);
                    break;
                case "white_7":
                    TreeGeneration(tree_seven);
                    break;
                // black keys function
                case "black_1":
                    ObjectControl(audio_one);
                    break;
                case "black_2":
                    ObjectControl(audio_two);
                    break;
                case "black_3":
                    ObjectControl(rain_mode);
                    break;
                case "black_4":
                    ObjectControl(audio_four);
                    break;
                case "black_5":
                    ObjectControl(audio_five);
                    break;
                // red button
                case "daytime_change":
                    LightControl();
                    break;
                // reset button
                case "reset":
                    SceneManager.LoadScene(0);
                    break;
               
            }
           

            
            
            yield return null;
        }
    }
    void Update()
    {
        
        
    }

    public void TreeGeneration(GameObject targetObject)
    {
        // Generate a random position within a defined range
        Vector3 randomPosition = new Vector3(Random.Range(-5f, 5f), Random.Range(-5f, 5f), Random.Range(-5f, 5f));
        
        // Instantiate the cube at the random position
        Instantiate(targetObject, randomPosition, Quaternion.identity);
    }

    public void LightControl() {
        if (dayLight.activeInHierarchy) {
            dayLight.SetActive(false);
        } else {
            dayLight.SetActive(true);
        }
    }

    public void ObjectControl(GameObject targetObject) {
        if (targetObject.activeInHierarchy) {
            targetObject.SetActive(false);
        } else {
            targetObject.SetActive(true);
        }
    }
}