using System;

public class Solution {
    public string solution(int[,] scores) {
        string answer = "";
        int arrayLength = scores.GetLength(0);
        int reducedArrayLength = arrayLength-1;
        
        for(int i=0; i<arrayLength; i++){
            int mine = scores[i,i];
            int max = -1;
            int min = 101;
            int sum = 0;
            
            for(int j=0; j<arrayLength; j++){
                int currentScore = scores[j,i];
                if(i==j){
                    continue;
                }
                
                sum+=currentScore;
                if(max<currentScore){
                    max = currentScore;
                }
                
                if(min>currentScore){
                    min = currentScore;
                }
            }
            
            float avg=0f;
            
            if(max==mine || min==mine || (min < mine && max > mine)){
                avg = (float)(sum + mine) / arrayLength;
            }else{
                avg = (float)sum / reducedArrayLength;
            }
            
            if(avg >=90){
                answer +="A";
            }else if(avg>=80){
                answer +="B";
            }else if(avg>=70){
                answer +="C";
            }else if(avg>=50){
                answer +="D";
            }else{
                answer +="F";
            }
        }
        
        return answer;
    }
}