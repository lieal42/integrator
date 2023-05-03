//
//  notabilityApp.swift
//  notability WatchKit Extension
//
//  Created by Fabio Pandolfi on 23/04/21.
//

import SwiftUI

@main
struct notabilityApp: App {
    @SceneBuilder var body: some Scene {
        WindowGroup {
            NavigationView {
                ContentView()
            }
        }

        WKNotificationScene(controller: NotificationController.self, category: "myCategory")
    }
}
