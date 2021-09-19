function solution(table, languages, preference) {
  let preferenceMap = {};
  var scoreMap = {};
  const categories = ["SI", "CONTENTS", "HARDWARE", "PORTAL", "GAME"];
  languages.forEach((language, index) => {
    preferenceMap[language] = preference[index];
  });
  categories.forEach((category) => {
    scoreMap[category] = 0;
  });
  table.forEach((languagesPerCategory, categoryIndex) => {
    const categoryName = categories[categoryIndex];
    const languagesArr = languagesPerCategory.split(" ");
    languagesArr.forEach((language, index) => {
      if (preferenceMap[language]) {
        scoreMap[categoryName] += preferenceMap[language] * (6 - index);
      }
    });
  });
  const orderedScoreMap = Object.keys(scoreMap)
    .sort()
    .reduce((obj, key) => {
      obj[key] = scoreMap[key];
      return obj;
    }, {});
  const maxScore = Math.max(...Object.values(orderedScoreMap));
  const recommended = Object.keys(orderedScoreMap).find(
    (key) => orderedScoreMap[key] === maxScore
  );
  return recommended;
}
