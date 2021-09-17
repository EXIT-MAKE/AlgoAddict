function solution(scores) {
  const studentNum = scores.length;
  let grades = "";
  const receivedScores = [...scores][0].map((_, c) =>
    scores.map((row) => row[c])
  );
  const scoreToGrade = (score) => {
    if (score >= 90) {
      return "A";
    } else if (score >= 80) {
      return "B";
    } else if (score >= 70) {
      return "C";
    } else if (score >= 50) {
      return "D";
    } else {
      return "F";
    }
  };
  receivedScores.forEach((scoresRow, receiver) => {
    let scoresAvg =
      scoresRow.reduce((accumulator, curr) => accumulator + curr) / studentNum;
    const maxScore = Math.max(...scoresRow);
    const minScore = Math.min(...scoresRow);
    scoresRow.forEach((score, evaluator) => {
      if (
        receiver === evaluator &&
        ((scoresRow.filter((data) => data === maxScore).length < 2 &&
          score === maxScore) ||
          (scoresRow.filter((data) => data === minScore).length < 2 &&
            score === minScore))
      ) {
        scoresAvg = (scoresAvg * studentNum - score) / (studentNum - 1);
      }
    });
    grades += scoreToGrade(scoresAvg);
  });
  return grades;
}
