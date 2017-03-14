module Robodex = {
  include ReactRe.Component.Stateful;
  type state = {robots: list RobotCard.robot, searchString: string};
  type props = unit;
  let name = "robodex";
  let getInitialState _ => {
    robots: [
      {id: "1", name: "Anton Merry"},
      {id: "2", name: "Stan Wobb"},
      {id: "3", name: "Victoria Watson"},
      {id: "4", name: "David Sanchez"},
      {id: "5", name: "Stephanie Underwood"},
      {id: "6", name: "Paul Bezenson"},
      {id: "7", name: "Doris Beckwith"},
      {id: "8", name: "Rusty cogsworth"},
      {id: "9", name: "Jeff Gearz"},
      {id: "10", name: "Sterling Gunn"}
    ],
    searchString: ""
  };
  let handleInputChange {state} event =>
    Some {...state, searchString: ReasonJs.Document.value event##target};
  let render {state, updater} => {
    let {robots, searchString} = state;
    let robotItems =
      robots |>
      List.filter (
        fun robot => {
          let robotName = String.lowercase RobotCard.(robot.name);
          let queryString = String.lowercase searchString;
          Js.String.includes queryString robotName
        }
      ) |>
      List.map (fun robot => <RobotCard key=robot.id robot />);
    <div>
      <div className="header">
        <img src="http://i.imgur.com/49C0QB7.png" alt="logo" className="logo" />
        <h1 className="header-title"> (ReactRe.stringToElement "rehydrate-robodex") </h1>
        <input
          className="search-bar"
          value=state.searchString
          placeholder="Search robots by name"
          onChange=(updater handleInputChange)
        />
      </div>
      <div className="robots-container"> (ReactRe.arrayToElement (Array.of_list robotItems)) </div>
    </div>
  };
};

include ReactRe.CreateComponent Robodex;

let createElement = wrapProps ();
