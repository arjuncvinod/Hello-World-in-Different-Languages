// randomHeroDiv=document.getElementById("randomHero")

// randomId=document.getElementById("randomId")



// const getHero=(id)=>{
//   fetch(`https://superheroapi.com/api.php/3608235279458714/${id}`)
// .then(response=>response.json())
// .then(json=>{(json.image.url)
//   randomHeroDiv.innerHTML=`<img src="${json.image.url}"/>`
// })
// }
// const d=prompt("Enter the token")
// getHero(d)


const token=3608235279458714
const base=`https://superheroapi.com/api.php/${token}`

randomHeroDiv=document.getElementById("randomHeroImg")

const SearchHero=document.getElementById("SearchHero")

const heroNameDiv=document.getElementById("heroName")

const powerStatsDiv=document.getElementById("powerStats")

const getHero=(id,name)=>{
  //name:base/search/batman
  fetch(`${base}/${id}`)
  .then(response=>response.json())
  .then(json=>{console.log(json.powerstats)
    // s=json.appearance.gender
    
    // if (s=="Male"){
    //   console.log(s,`${id}`)
    // }
    // else if (s=="Female"){
    //   console.log(s,`${id}`)
    // }
      
    

    
     const stats=getStatsHTML(json)
    
    randomHeroDiv.innerHTML=`<img src="${json.image.url}" height=200 width=200/>${stats}`
    heroNameDiv.innerHTML= `<h2>${json.name.toUpperCase()}</h2>`
     
    
  })
  
  
}

const getStatsHTML=(character)=>{
  const stats=Object.keys(character.powerstats).map(stat=>{
    return `<p>${stat.toUpperCase()}:${character.powerstats[stat]}</p>`
  })

  console.log(stats.join(" "))
  return stats.join(" ")
  
  
}



const randomHero=document.getElementById("randomHero")

const getSearchedHero=(name)=>{
  console.log(writeHereDiv.value)
  fetch(`${base}/search/${name}`)
  .then(response=>response.json())
  .then(json=>{ hero=json.results[0]
  console.log(hero)

  s=hero.appearance.gender
    
    if (s=="Male"){
      console.log(s)
    }
    else if (s=="Female"){
      console.log(s)
    }
  const stats=getStatsHTML(json.results[0])
    
  randomHeroDiv.innerHTML=`<img 
  src="${hero.image.url}" height=200 width=200/> ${stats}`
  heroNameDiv.innerHTML= `<h2>${hero.name.toUpperCase()}</h2>`
  })
}

const randomNumber=()=>{
  const numberOfHeroes=732
  return Math.floor(Math.random()*numberOfHeroes)+1
}

randomHero.onclick=()=>{
  getHero(randomNumber())
}

writeHereDiv=document.getElementById("writeHere")



SearchHero.onclick=()=>{
  getSearchedHero(writeHereDiv.value)
}

// Malebut=document.getElementById("Male")

// getGender=(d)=>{
  
  
//   fetch(`${base}/${d}`)
//   .then(response=>response.json())
//   .then(json=>{
//     s=json.appearance.gender
//     if(s=="Male"){
//       Malebut.onclick=()=>{
//         getHero(d)
//       }
      
//     }

//   })
  
// }

// r=randomNumber()

// getGender(r)







// // if(getGender()=="Male"){
// //   Malebut.onclick=()=>{
// //     getHero(s)
// //   }
  
// // }









  










