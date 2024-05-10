using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Click : MonoBehaviour
{
    public GameObject cube;

    public void GenerateRandomCube()
    {
        // Generate a random position within a defined range
        Vector3 randomPosition = new Vector3(Random.Range(-5f, 5f), Random.Range(-5f, 5f), Random.Range(-5f, 5f));
        
        // Instantiate the cube at the random position
        Instantiate(cube, randomPosition, Quaternion.identity);
    }
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
